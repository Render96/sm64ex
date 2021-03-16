#include "dynos.cpp.h"
extern "C" {
#include "game/area.h"
#include "r96/system/r96_system.h"
}

#define AUDIO_BUFFER_SIZE	0x200
#define AUDIO_FREQUENCY_32000   32000
#define AUDIO_FREQUENCY_44100   44100
#define AUDIO_FORMAT		AUDIO_S16SYS
#define MUSIC_CHANNELS		2
#define SOUND_CHANNELS		1

static bool TokenizeBuffer(char *aBuffer, char **aTokens, s32 aTokenMax) {
    bool dq = false;
    for (char *p = NULL; *aBuffer != 0 && aTokenMax > 0; ++aBuffer) {
        u8 c = (u8) *aBuffer;
        if ((c <= 0x20 && !dq) || (c == '\"' && dq)) {
            if (p) {
                *(aTokens++) = p;
                aTokenMax--;
                p = NULL;
            }
            *aBuffer = 0;
            dq = false;
        } else if (c == '\"' && !dq) {
            dq = true;
        } else if (!p) {
            p = aBuffer;
        }
    }
    return (aTokenMax == 0);
}

//
// Audio
//

// Volume ranges from 0 to 1
extern u16 sAcousticReachPerLevel[];
void DynOS_Audio_Mix(u8 *aOutput, const u8 *aInput, s32 aLength, f32 aVolume, f32 aDistance) {
    f32 _AcrVolume = MIN(MAX(1.f - MIN(1.f, absx(aDistance) / sAcousticReachPerLevel[gCurrLevelNum]), 0.f), 1.f);
    f32 _MixVolume = MIN(MAX(aVolume * sqr(_AcrVolume), 0.f), 1.f);
    for (s32 i = 0; i < aLength; i += sizeof(s16)) {
        s16 *_In = (s16 *) (aInput + i);
        s16 *_Out = (s16 *) (aOutput + i);
        *_Out = (s16) (((f32) *_In) * _MixVolume);
    }
}

//
// Music
//

struct MusicData {
    String mName;
    u8 *mData;
    s32 mLength;
    s32 mLoop;
    s32 mCurrent;
    f32 mVolume;
    f32 mVolMulti;
    s32 mFadeTime;
    s32 mFadeIn;
};

s32 mCurrentMultiTrack = 0;

STATIC_STORAGE(Array<MusicData *>, LoadedMusics);
#define sLoadedMusics __LoadedMusics()

STATIC_STORAGE(MusicData *, PlayingMusic);
#define sPlayingMusic __PlayingMusic()

void DynOS_Music_FadeIn();

static void DynOS_Music_Callback(UNUSED void *, u8 *aStream, s32 aLength) {
    bzero(aStream, aLength);
    if (sPlayingMusic == NULL) {
        return;
    }

    f32 _Volume = sPlayingMusic->mVolume * (configMasterVolume / 127.f) * (configMusicVolume / 127.f) * softenVolume * sPlayingMusic->mVolMulti;
    s32 _LenTilEnd = sPlayingMusic->mLength - sPlayingMusic->mCurrent;
    if (_LenTilEnd < aLength) {
        DynOS_Audio_Mix(aStream, sPlayingMusic->mData + sPlayingMusic->mCurrent, _LenTilEnd, _Volume, 0);
        if (sPlayingMusic->mLoop != 0) {
            DynOS_Audio_Mix(aStream + _LenTilEnd, sPlayingMusic->mData + sPlayingMusic->mLoop, aLength - _LenTilEnd, _Volume, 0);
            sPlayingMusic->mCurrent = sPlayingMusic->mLoop + (aLength - _LenTilEnd);
        } else {
            sPlayingMusic = NULL;
        }
    } else {
        DynOS_Audio_Mix(aStream, sPlayingMusic->mData + sPlayingMusic->mCurrent, aLength, _Volume, 0);
        sPlayingMusic->mCurrent += aLength;
        mCurrentMultiTrack = sPlayingMusic->mCurrent;
        if (sPlayingMusic->mFadeIn == 1) {
            if (sPlayingMusic->mFadeTime != 0) {
                DynOS_Music_FadeIn();
            }
        }
        
    }
}

static SDL_AudioDeviceID DynOS_Music_GetDevice() {
    static SDL_AudioDeviceID sMusicDeviceId = 0;
    if (sMusicDeviceId) {
        return sMusicDeviceId;
    }

    // Init SDL2 Audio
    if (!SDL_WasInit(SDL_INIT_AUDIO)) {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
            sys_fatal("DynOS_Music_GetDevice: Could not init SDL Audio.");
        }
    }

    // Open music device
    SDL_AudioSpec _Want, _Have;
    _Want.freq     = AUDIO_FREQUENCY_44100;
    _Want.format   = AUDIO_FORMAT;
    _Want.channels = MUSIC_CHANNELS;
    _Want.samples  = AUDIO_BUFFER_SIZE;
    _Want.callback = DynOS_Music_Callback;
    _Want.userdata = NULL;
    sMusicDeviceId = SDL_OpenAudioDevice(NULL, 0, &_Want, &_Have, 0);
    if (sMusicDeviceId == 0) {
        sys_fatal("DynOS_Music_GetDevice: Could not open music device.");
    }
    SDL_PauseAudioDevice(sMusicDeviceId, 0);
    return sMusicDeviceId;
}

bool DynOS_Music_LoadRaw(const String &aName, const u8 *aData, s32 aLength, s32 aLoop, f32 aVolume) {
    if (sLoadedMusics.FindIf([&aName](const MusicData *aMusicData) { return aMusicData->mName == aName; }) != -1) {
        return false;
    }

    MusicData *_MusicData = New<MusicData>();
    _MusicData->mName     = aName;
    _MusicData->mData     = CopyBytes(aData, aLength * sizeof(u8));
    _MusicData->mLength   = aLength;
    _MusicData->mLoop     = aLoop * sizeof(s16) * MUSIC_CHANNELS;
    _MusicData->mCurrent  = 0;
    _MusicData->mVolume   = aVolume;
    _MusicData->mVolMulti = 0.0f;
    _MusicData->mFadeTime = 1000;
    _MusicData->mFadeIn   = 0;
    sLoadedMusics.Add(_MusicData);
    return true;
}

bool DynOS_Music_LoadWav(const String &aName, const SysPath &aFilename, s32 aLoop, f32 aVolume) {
    if (sLoadedMusics.FindIf([&aName](const MusicData *aMusicData) { return aMusicData->mName == aName; }) != -1) {
        return false;
    }

    SDL_AudioSpec _Spec;
    u8 *_Data;
    s32 _Length;
    if (!SDL_LoadWAV(aFilename.c_str(), &_Spec, &_Data, (u32 *) &_Length)) {
        sys_fatal("DynOS_Music_LoadWav: Unable to load file %s.", aFilename.c_str());
        return false;
    }
    if (_Spec.freq != AUDIO_FREQUENCY_44100) {
        sys_fatal("DynOS_Music_LoadWav: From file %s, audio frequency should be %d, is %d.", aFilename.c_str(), AUDIO_FREQUENCY_44100, _Spec.freq);
        return false;
    }
    if (_Spec.format != AUDIO_FORMAT) {
        sys_fatal("DynOS_Music_LoadWav: From file %s, audio format is not Signed 16-bit PCM.", aFilename.c_str());
        return false;
    }
    if (_Spec.channels != MUSIC_CHANNELS) {
        sys_fatal("DynOS_Music_LoadWav: From file %s, audio channel count should be %d, is %d.", aFilename.c_str(), MUSIC_CHANNELS, _Spec.channels);
        return false;
    }

    MusicData *_MusicData = New<MusicData>();
    _MusicData->mName     = aName;
    _MusicData->mData     = _Data;
    _MusicData->mLength   = _Length;
    _MusicData->mLoop     = aLoop * sizeof(s16) * MUSIC_CHANNELS;
    _MusicData->mCurrent  = 0;
    _MusicData->mVolume   = aVolume;
    _MusicData->mVolMulti = 0.0f;
    _MusicData->mFadeTime = 1000;
    _MusicData->mFadeIn   = 0;
    sLoadedMusics.Add(_MusicData);
    return true;
}

// The file format is a simple txt file
// Each line is something like this:
// [name] [filename] [volume] [loop]
// - name is the internal id used by the music
// - filename (.wav can be omitted)
// - volume ranges from 0 to 127
// - loop can be any positive integer, any negative value acts as no loop
bool DynOS_Music_LoadPresets(const SysPath &aFilename, const SysPath &aFolder) {
    FILE *_File = fopen(aFilename.c_str(), "r");
    if (_File) {
        char _Buffer[1024];
        while (fgets(_Buffer, 1024, _File)) {
            char *_Tokens[4];
            if (TokenizeBuffer(_Buffer, _Tokens, 4)) {
                SysPath _Filename = aFolder + "/" + _Tokens[1];
                if (_Filename.find(".wav") == SysPath::npos &&
                    _Filename.find(".WAV") == SysPath::npos) {
                    _Filename += ".wav";
                }
                DynOS_Music_LoadWav(_Tokens[0], _Filename, String(_Tokens[3]).ParseInt(), String(_Tokens[2]).ParseInt() / 127.f);
            }
        }
        fclose(_File);
        return true;
    }
    return false;
}

void DynOS_Music_Play(const String& aName) {
    s32 _MusicDataIndex = sLoadedMusics.FindIf([&aName](const MusicData *aMusicData) { return aMusicData->mName == aName; });
    if (_MusicDataIndex == -1) {
        return;
    }
    SDL_LockAudioDevice(DynOS_Music_GetDevice());
    sPlayingMusic = sLoadedMusics[_MusicDataIndex];
    sPlayingMusic->mCurrent = 0;
    SDL_UnlockAudioDevice(DynOS_Music_GetDevice());
    SDL_PauseAudioDevice(DynOS_Music_GetDevice(), false);
    sPlayingMusic->mFadeIn = 1;
    sPlayingMusic->mVolMulti = 0.0f;
    DynOS_Music_FadeIn();
}

void DynOS_Music_Multi_Play(const String& aName) {
    s32 _MusicDataIndex = sLoadedMusics.FindIf([&aName](const MusicData *aMusicData) { return aMusicData->mName == aName; });
    if (_MusicDataIndex == -1) {
        return;
    }

    SDL_LockAudioDevice(DynOS_Music_GetDevice());
    sPlayingMusic = sLoadedMusics[_MusicDataIndex];
    sPlayingMusic->mCurrent = mCurrentMultiTrack;
    SDL_UnlockAudioDevice(DynOS_Music_GetDevice());
    SDL_PauseAudioDevice(DynOS_Music_GetDevice(), false);
    sPlayingMusic->mFadeIn = 1;
    sPlayingMusic->mVolMulti = 0.0f;
    DynOS_Music_FadeIn();
}

void DynOS_Music_Stop() {
    SDL_LockAudioDevice(DynOS_Music_GetDevice());
    mCurrentMultiTrack = 0;
    sPlayingMusic = NULL;
    SDL_UnlockAudioDevice(DynOS_Music_GetDevice());
    SDL_PauseAudioDevice(DynOS_Music_GetDevice(), true);
}

void DynOS_Music_Pause() {
    SDL_PauseAudioDevice(DynOS_Music_GetDevice(), TRUE);
}

void DynOS_Music_Resume() {
    SDL_PauseAudioDevice(DynOS_Music_GetDevice(), FALSE);
}

bool DynOS_Music_IsPlaying(const String& aName) {
    return (sPlayingMusic != NULL) && (aName.Empty() || sPlayingMusic->mName == aName);
}

void DynOS_Music_FadeIn() {
    if (sPlayingMusic->mFadeTime > 0) {
        sPlayingMusic->mVolMulti += 0.01f;
        sPlayingMusic->mFadeTime -= 10;
    }
    if (sPlayingMusic->mFadeTime == 0) {
        sPlayingMusic->mFadeIn = 0;
        sPlayingMusic->mVolMulti = 1.0f;
        sPlayingMusic->mFadeTime = 1000;
    }
}

//
// Sound
//

struct SoundData {
    String mName;
    u8 *mData[2];
    s32 mLength;
    f32 mVolume;
    u8 mPriority;
    u8 mBank;
};

STATIC_STORAGE(Array<SoundData *>, LoadedSounds);
#define sLoadedSounds __LoadedSounds()

STATIC_STORAGE(SoundData *, PlayingSound);
#define sPlayingSound __PlayingSound()

static SDL_AudioDeviceID DynOS_Sound_GetDevice(u8 aBank) {
    static SDL_AudioDeviceID sSoundDeviceId[0x100] = { 0 };
    if (sSoundDeviceId[aBank]) {
        return sSoundDeviceId[aBank];
    }

    // Init SDL2 Audio
    if (!SDL_WasInit(SDL_INIT_AUDIO)) {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
            sys_fatal("DynOS_Sound_GetDevice: Could not init SDL Audio.");
        }
    }

    // Open sound device
    SDL_AudioSpec _Want, _Have;
    _Want.freq     = AUDIO_FREQUENCY_32000;
    _Want.format   = AUDIO_FORMAT;
    _Want.channels = SOUND_CHANNELS;
    _Want.samples  = AUDIO_BUFFER_SIZE;
    _Want.callback = NULL;
    _Want.userdata = NULL;
    sSoundDeviceId[aBank] = SDL_OpenAudioDevice(NULL, 0, &_Want, &_Have, 0);
    if (sSoundDeviceId == 0) {
        sys_fatal("DynOS_Sound_GetDevice: Could not open sound device.");
    }
    SDL_PauseAudioDevice(sSoundDeviceId[aBank], 0);
    return sSoundDeviceId[aBank];
}

bool DynOS_Sound_LoadRaw(const String& aName, u8 aBank, const u8 *aData, s32 aLength, f32 aVolume, u8 aPriority) {
    if (sLoadedSounds.FindIf([&aName](const SoundData *aSoundData) { return aSoundData->mName == aName; }) != -1) {
        return false;
    }

    SoundData *_SoundData = New<SoundData>();
    _SoundData->mName     = aName;
    _SoundData->mData[0]  = CopyBytes(aData, aLength * sizeof(u8));
    _SoundData->mData[1]  = CopyBytes(aData, aLength * sizeof(u8));
    _SoundData->mLength   = aLength;
    _SoundData->mVolume   = aVolume;
    _SoundData->mPriority = aPriority;
    _SoundData->mBank     = aBank;
    sLoadedSounds.Add(_SoundData);
    return true;
}

bool DynOS_Sound_LoadWav(const String& aName, u8 aBank, const SysPath& aFilename, f32 aVolume, u8 aPriority) {
    if (sLoadedSounds.FindIf([&aName](const SoundData *aSoundData) { return aSoundData->mName == aName; }) != -1) {
        return false;
    }

    SDL_AudioSpec _Spec;
    u8 *_Data;
    s32 _Length;
    if (!SDL_LoadWAV(aFilename.c_str(), &_Spec, &_Data, (u32 *) &_Length)) {
        sys_fatal("DynOS_Sound_LoadWav: Unable to load file %s.", aFilename.c_str());
        return false;
    }
    if (_Spec.freq != AUDIO_FREQUENCY_32000) {
        sys_fatal("DynOS_Sound_LoadWav: From file %s, audio frequency should be %d, is %d.", aFilename.c_str(), AUDIO_FREQUENCY_32000, _Spec.freq);
        return false;
    }
    if (_Spec.format != AUDIO_FORMAT) {
        sys_fatal("DynOS_Sound_LoadWav: From file %s, audio format is not Signed 16-bit PCM.", aFilename.c_str());
        return false;
    }
    if (_Spec.channels != SOUND_CHANNELS) {
        sys_fatal("DynOS_Sound_LoadWav: From file %s, audio channel count should be %d, is %d.", aFilename.c_str(), SOUND_CHANNELS, _Spec.channels);
        return false;
    }

    SoundData *_SoundData = New<SoundData>();
    _SoundData->mName     = aName;
    _SoundData->mData[0]  = _Data;
    _SoundData->mData[1]  = CopyBytes(_Data, _Length * sizeof(u8));
    _SoundData->mLength   = _Length;
    _SoundData->mVolume   = aVolume;
    _SoundData->mPriority = aPriority;
    _SoundData->mBank     = aBank;
    sLoadedSounds.Add(_SoundData);
    return true;
}

// The file format is a simple txt file
// Each line is something like this:
// [name] [filename] [volume] [bank] [priority]
// - name is the internal id used by the music
// - filename (.wav can be omitted)
// - volume ranges from 0 to 127
// - bank ranges from 0 to 255
// - priority ranges from 0 to 255
bool DynOS_Sound_LoadPresets(const SysPath &aFilename, const SysPath &aFolder) {
    FILE *_File = fopen(aFilename.c_str(), "r");
    if (_File) {
        char _Buffer[1024];
        while (fgets(_Buffer, 1024, _File)) {
            char *_Tokens[5];
            if (TokenizeBuffer(_Buffer, _Tokens, 5)) {
                SysPath _Filename = aFolder + "/" + _Tokens[1];
                if (_Filename.find(".wav") == SysPath::npos &&
                    _Filename.find(".WAV") == SysPath::npos) {
                    _Filename += ".wav";
                }
                DynOS_Sound_LoadWav(_Tokens[0], String(_Tokens[3]).ParseInt(), _Filename, String(_Tokens[2]).ParseInt() / 127.f, String(_Tokens[4]).ParseInt());
            }
        }
        fclose(_File);
        return true;
    }
    return false;
}

void DynOS_Sound_Play(const String& aName, f32 *aPos) {
    s32 _SoundDataIndex = sLoadedSounds.FindIf([&aName](const SoundData *aSoundData) { return aSoundData->mName == aName; });
    if (_SoundDataIndex == -1) {
        return;
    }

    // Sound data
    SoundData *_SoundData = sLoadedSounds[_SoundDataIndex];
    if (!_SoundData) {
        return;
    }

    // Update playing sound
    if (SDL_GetQueuedAudioSize(DynOS_Sound_GetDevice(_SoundData->mBank)) == 0) {
        sPlayingSound = NULL;
    }

    // Don't overwrite playing sounds with higher priority
    // Sounds with equal priority cancel out each other
    if (sPlayingSound != NULL && sPlayingSound->mPriority > _SoundData->mPriority) {
        return;
    }

    f32 aVolume = _SoundData->mVolume * (configMasterVolume / 127.f) * (configSfxVolume / 127.f);
    f32 aDistance = (aPos == NULL ? 0 : vec3f_length(aPos));
    DynOS_Audio_Mix(_SoundData->mData[1], _SoundData->mData[0], _SoundData->mLength, aVolume, aDistance);
    SDL_ClearQueuedAudio(DynOS_Sound_GetDevice(_SoundData->mBank));
    SDL_QueueAudio(DynOS_Sound_GetDevice(_SoundData->mBank), _SoundData->mData[1], _SoundData->mLength);
    sPlayingSound = _SoundData;
}

void DynOS_Sound_Stop(u8 aBank) {
    SDL_ClearQueuedAudio(DynOS_Sound_GetDevice(aBank));
    sPlayingSound = NULL;
}

bool DynOS_Sound_IsPlaying(const String& aName) {
    s32 _SoundDataIndex = sLoadedSounds.FindIf([&aName](const SoundData *aSoundData) { return aSoundData->mName == aName; });
    if (_SoundDataIndex == -1) {
        return false;
    }

    // Sound data
    SoundData *_SoundData = sLoadedSounds[_SoundDataIndex];
    if (!_SoundData) {
        return false;
    }

    // Update playing sound
    if (SDL_GetQueuedAudioSize(DynOS_Sound_GetDevice(_SoundData->mBank)) == 0) {
        sPlayingSound = NULL;
        return false;
    }

    // Playing
    return (sPlayingSound == _SoundData);
}

bool DynOS_Sound_IsPlaying(u8 aBank) {
    return SDL_GetQueuedAudioSize(DynOS_Sound_GetDevice(aBank)) != 0;
}

//
// Jingle
//

struct JingleData {
    String mName;
    u8 *mData;
    s32 mLength;
    s32 mLoop;
    s32 mCurrent;
    f32 mVolume;
    f32 mVolMulti;
    s32 mFadeTime;
    s32 mFadeIn;
};

STATIC_STORAGE(Array<JingleData *>, LoadedJingles);
#define sLoadedJingles __LoadedJingles()

STATIC_STORAGE(JingleData *, PlayingJingle);
#define sPlayingJingle __PlayingJingle()

void DynOS_Jingle_FadeIn();

static void DynOS_Jingle_Callback(UNUSED void *, u8 *aStream, s32 aLength) {
    bzero(aStream, aLength);
    if (sPlayingJingle == NULL) {
        return;
    }

    f32 _Volume = sPlayingJingle->mVolume * (configMasterVolume / 127.f) * (configMusicVolume / 127.f) * softenJingleVolume * sPlayingJingle->mVolMulti;
    s32 _LenTilEnd = sPlayingJingle->mLength - sPlayingJingle->mCurrent;
    if (_LenTilEnd < aLength) {
        DynOS_Audio_Mix(aStream, sPlayingJingle->mData + sPlayingJingle->mCurrent, _LenTilEnd, _Volume, 0);
        if (sPlayingJingle->mLoop != 0) {
            DynOS_Audio_Mix(aStream + _LenTilEnd, sPlayingJingle->mData + sPlayingJingle->mLoop, aLength - _LenTilEnd, _Volume, 0);
            sPlayingJingle->mCurrent = sPlayingJingle->mLoop + (aLength - _LenTilEnd);
        } else {
            sPlayingJingle = NULL;
        }
    } else {
        DynOS_Audio_Mix(aStream, sPlayingJingle->mData + sPlayingJingle->mCurrent, aLength, _Volume, 0);
        sPlayingJingle->mCurrent += aLength;
        if (sPlayingJingle->mFadeIn == 1) {
            if (sPlayingJingle->mFadeTime != 0) {
                DynOS_Jingle_FadeIn();
            }
        }
    }
}

static SDL_AudioDeviceID DynOS_Jingle_GetDevice() {
    static SDL_AudioDeviceID sJingleDeviceId = 0;
    if (sJingleDeviceId) {
        return sJingleDeviceId;
    }

    // Init SDL2 Audio
    if (!SDL_WasInit(SDL_INIT_AUDIO)) {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
            sys_fatal("DynOS_Jingle_GetDevice: Could not init SDL Audio.");
        }
    }

    // Open jingle device
    SDL_AudioSpec _Want, _Have;
    _Want.freq     = AUDIO_FREQUENCY_44100;
    _Want.format   = AUDIO_FORMAT;
    _Want.channels = MUSIC_CHANNELS;
    _Want.samples  = AUDIO_BUFFER_SIZE;
    _Want.callback = DynOS_Jingle_Callback;
    _Want.userdata = NULL;
    sJingleDeviceId = SDL_OpenAudioDevice(NULL, 0, &_Want, &_Have, 0);
    if (sJingleDeviceId == 0) {
        sys_fatal("DynOS_Jingle_GetDevice: Could not open jingle device.");
    }
    SDL_PauseAudioDevice(sJingleDeviceId, 0);
    return sJingleDeviceId;
}

bool DynOS_Jingle_LoadRaw(const String &aName, const u8 *aData, s32 aLength, s32 aLoop, f32 aVolume) {
    if (sLoadedJingles.FindIf([&aName](const JingleData *aJingleData) { return aJingleData->mName == aName; }) != -1) {
        return false;
    }

    JingleData *_JingleData = New<JingleData>();
    _JingleData->mName     = aName;
    _JingleData->mData     = CopyBytes(aData, aLength * sizeof(u8));
    _JingleData->mLength   = aLength;
    _JingleData->mLoop     = aLoop * sizeof(s16) * MUSIC_CHANNELS;
    _JingleData->mCurrent  = 0;
    _JingleData->mVolume   = aVolume;
    _JingleData->mVolMulti = 0.0f;
    _JingleData->mFadeTime = 1000;
    _JingleData->mFadeIn   = 0;
    sLoadedJingles.Add(_JingleData);
    return true;
}

bool DynOS_Jingle_LoadWav(const String &aName, const SysPath &aFilename, s32 aLoop, f32 aVolume) {
    if (sLoadedJingles.FindIf([&aName](const JingleData *aJingleData) { return aJingleData->mName == aName; }) != -1) {
        return false;
    }

    SDL_AudioSpec _Spec;
    u8 *_Data;
    s32 _Length;
    if (!SDL_LoadWAV(aFilename.c_str(), &_Spec, &_Data, (u32 *) &_Length)) {
        sys_fatal("DynOS_Jingle_LoadWav: Unable to load file %s.", aFilename.c_str());
        return false;
    }
    if (_Spec.freq != AUDIO_FREQUENCY_44100) {
        sys_fatal("DynOS_Jingle_LoadWav: From file %s, audio frequency should be %d, is %d.", aFilename.c_str(), AUDIO_FREQUENCY_44100, _Spec.freq);
        return false;
    }
    if (_Spec.format != AUDIO_FORMAT) {
        sys_fatal("DynOS_Jingle_LoadWav: From file %s, audio format is not Signed 16-bit PCM.", aFilename.c_str());
        return false;
    }
    if (_Spec.channels != MUSIC_CHANNELS) {
        sys_fatal("DynOS_Jingle_LoadWav: From file %s, audio channel count should be %d, is %d.", aFilename.c_str(), MUSIC_CHANNELS, _Spec.channels);
        return false;
    }

    JingleData *_JingleData = New<JingleData>();
    _JingleData->mName     = aName;
    _JingleData->mData     = _Data;
    _JingleData->mLength   = _Length;
    _JingleData->mLoop     = aLoop * sizeof(s16) * MUSIC_CHANNELS;
    _JingleData->mCurrent  = 0;
    _JingleData->mVolume   = aVolume;
    _JingleData->mVolMulti = 0.0f;
    _JingleData->mFadeTime = 1000;
    _JingleData->mFadeIn   = 0;
    sLoadedJingles.Add(_JingleData);
    return true;
}

// The file format is a simple txt file
// Each line is something like this:
// [name] [filename] [volume] [loop]
// - name is the internal id used by the jingle
// - filename (.wav can be omitted)
// - volume ranges from 0 to 127
// - loop can be any positive integer, any negative value acts as no loop
bool DynOS_Jingle_LoadPresets(const SysPath &aFilename, const SysPath &aFolder) {
    FILE *_File = fopen(aFilename.c_str(), "r");
    if (_File) {
        char _Buffer[1024];
        while (fgets(_Buffer, 1024, _File)) {
            char *_Tokens[4];
            if (TokenizeBuffer(_Buffer, _Tokens, 4)) {
                SysPath _Filename = aFolder + "/" + _Tokens[1];
                if (_Filename.find(".wav") == SysPath::npos &&
                    _Filename.find(".WAV") == SysPath::npos) {
                    _Filename += ".wav";
                }
                DynOS_Jingle_LoadWav(_Tokens[0], _Filename, String(_Tokens[3]).ParseInt(), String(_Tokens[2]).ParseInt() / 127.f);
            }
        }
        fclose(_File);
        return true;
    }
    return false;
}

void DynOS_Jingle_Play(const String& aName) {
    s32 _JingleDataIndex = sLoadedJingles.FindIf([&aName](const JingleData *aJingleData) { return aJingleData->mName == aName; });
    if (_JingleDataIndex == -1) {
        return;
    }

    SDL_LockAudioDevice(DynOS_Jingle_GetDevice());
    sPlayingJingle = sLoadedJingles[_JingleDataIndex];
    sPlayingJingle->mCurrent = 0;
    SDL_UnlockAudioDevice(DynOS_Jingle_GetDevice());
    SDL_PauseAudioDevice(DynOS_Jingle_GetDevice(), false);
    sPlayingJingle->mFadeIn = 1;
    sPlayingJingle->mVolMulti = 0.0f;
    DynOS_Jingle_FadeIn();
}

void DynOS_Jingle_Stop() {
    SDL_LockAudioDevice(DynOS_Jingle_GetDevice());
    sPlayingJingle = NULL;
    SDL_UnlockAudioDevice(DynOS_Jingle_GetDevice());
    SDL_PauseAudioDevice(DynOS_Jingle_GetDevice(), true);
}

void DynOS_Jingle_Pause() {
    SDL_PauseAudioDevice(DynOS_Jingle_GetDevice(), TRUE);
}

void DynOS_Jingle_Resume() {
    SDL_PauseAudioDevice(DynOS_Jingle_GetDevice(), FALSE);
}

bool DynOS_Jingle_IsPlaying(const String& aName) {
    return (sPlayingJingle != NULL) && (aName.Empty() || sPlayingJingle->mName == aName);
}

void DynOS_Jingle_FadeIn() {
    if (sPlayingJingle->mFadeTime > 0) {
        sPlayingJingle->mVolMulti += 0.01f;
        sPlayingJingle->mFadeTime -= 10;
    }
    if (sPlayingJingle->mFadeTime == 0) {
        sPlayingJingle->mFadeIn = 0;
        sPlayingJingle->mVolMulti = 1.0f;
        sPlayingJingle->mFadeTime = 1000;
    }
}