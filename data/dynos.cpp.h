#ifndef DYNOS_CPP_H
#define DYNOS_CPP_H
#ifdef __cplusplus

#include "dynos.h"

#undef STATIC_ASSERT
#define STATIC_ASSERT(...)

#define FUNCTION_CODE       (u32) 0x434E5546
#define POINTER_CODE        (u32) 0x52544E50
#define METAL_BITS          (G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR)
#define GFX_DYN_CMD_ID      "GFXDYNCMD_"

#define DYNOS_COURSE_NO_WARP(level)     (DynOS_Level_GetCourse(level) == COURSE_NONE)

// The action signature is "bool (*) (const char *)"
// The input is the button internal name (not label)
// The output is the result of the action
#define DYNOS_DEFINE_ACTION(func) \
AT_STARTUP static void DynOS_Opt_AddAction_##func() { \
    DynOS_Opt_AddAction(#func, func, false); \
}

//
// Enums
//

enum {
    DATA_TYPE_NONE = 0,
    DATA_TYPE_LIGHT,
    DATA_TYPE_TEXTURE,
    DATA_TYPE_VERTEX,
    DATA_TYPE_DISPLAY_LIST,
    DATA_TYPE_GEO_LAYOUT,
    DATA_TYPE_ANIMATION_VALUE,
    DATA_TYPE_ANIMATION_INDEX,
    DATA_TYPE_ANIMATION,
    DATA_TYPE_ANIMATION_TABLE,
    DATA_TYPE_GFXDYNCMD,
    DATA_TYPE_UNUSED,
};

enum {
    GFXDYNCMD_NONE = 0,
    GFXDYNCMD_CAPPY_EYES,
};

enum {
    DOPT_NONE = 0,

    DOPT_TOGGLE,
    DOPT_CHOICE,
    DOPT_SCROLL,
    DOPT_BIND,
    DOPT_BUTTON,
    DOPT_SUBMENU,

    // These ones are used by the Warp to Level built-in submenu
    DOPT_CHOICELEVEL,
    DOPT_CHOICESTAR,
    DOPT_CHOICEPARAM,

#ifdef RENDER_96_ALPHA
    DOPT_LANGUAGE,
#endif
};


//
// DynOS Array
// A Array-like array, implemented to be processed really fast, but cannot handle C++ complex classes like std::string
//

template <typename T>
class Array {
public:
    inline Array() : mBuffer(NULL), mCount(0), mCapacity(0) {
    }

    inline Array(const std::initializer_list<T> &aList) : mBuffer(NULL), mCount(0), mCapacity(0) {
        Resize(aList.size());
        memcpy(mBuffer, aList.begin(), mCount * sizeof(T));
    }

    inline Array(const T *aBegin, const T *aEnd) : mBuffer(NULL), mCount(0), mCapacity(0) {
        Resize(aEnd - aBegin);
        memcpy(mBuffer, aBegin, mCount * sizeof(T));
    }

    inline Array(const Array &aOther) : mBuffer(NULL), mCount(0), mCapacity(0) {
        Resize(aOther.mCount);
        memcpy(mBuffer, aOther.mBuffer, mCount * sizeof(T));
    }

    inline void operator=(const Array &aOther) {
        Resize(aOther.mCount);
        memcpy(mBuffer, aOther.mBuffer, mCount * sizeof(T));
    }

    inline ~Array() {
        Clear();
    }

public:
    void Resize(s32 aCount) {
        if (aCount > mCapacity) {
            mCapacity = MAX(aCount, MAX(16, mCapacity * 2));
            T *_Buffer = (T *) calloc(mCapacity, sizeof(T));
            if (mBuffer) {
                memcpy(_Buffer, mBuffer, mCount * sizeof(T));
                free(mBuffer);
            }
            mBuffer = _Buffer;
        }
        mCount = aCount;
    }

    void Add(const T& aItem) {
        Resize(mCount + 1);
        mBuffer[mCount - 1] = aItem;
    }

    void Remove(s32 aIndex) {
        memmove(mBuffer + aIndex, mBuffer + aIndex + 1, (mCount - aIndex - 1) * sizeof(T));
        mCount--;
    }

    void Pop() {
        mCount--;
    }

    void RemoveAll() {
        mCount = 0;
    }

    void Clear() {
        if (mBuffer) free(mBuffer);
        mBuffer   = NULL;
        mCount    = 0;
        mCapacity = 0;
    }

    s32 Find(const T& aItem) const {
        for (s32 i = 0; i != mCount; ++i) {
            if (mBuffer[i] == aItem) {
                return i;
            }
        }
        return -1;
    }

    template <typename Predicate>
    s32 FindIf(Predicate aPredicate) const {
        for (s32 i = 0; i != mCount; ++i) {
            if (aPredicate(mBuffer[i])) {
                return i;
            }
        }
        return -1;
    }

public:
    inline const T *begin() const { return mBuffer; }
    inline const T *end() const { return mBuffer + mCount; }
    inline T *begin() { return mBuffer; }
    inline T *end() { return mBuffer + mCount; }

    inline const T &operator[](s32 aIndex) const { return mBuffer[aIndex]; }
    inline T &operator[](s32 aIndex) { return mBuffer[aIndex]; }

    inline s32 Count() const { return mCount; }
    inline bool Empty() const { return mCount == 0; }

public:
    void Read(FILE *aFile) {
        s32 _Length = 0; fread(&_Length, sizeof(s32), 1, aFile);
        Resize(_Length);
        fread(mBuffer, sizeof(T), _Length, aFile);
    }

    void Write(FILE *aFile) const {
        fwrite(&mCount, sizeof(s32), 1, aFile);
        fwrite(mBuffer, sizeof(T), mCount, aFile);
    }

private:
    T *mBuffer;
    s32 mCount;
    s32 mCapacity;
};

//
// DynOS String
// A fixed-size string that doesn't require heap memory allocation
//

#define STRING_SIZE 95
class String {
public:
    inline String() : mCount(0) {
        mBuffer[0] = 0;
    }

    inline String(const char *aString) : mCount(0) {
        if (aString) {
            u64 _Length = strlen(aString);
            mCount = MIN(_Length, STRING_SIZE - 1);
            memcpy(mBuffer, aString, _Length);
        }
        mBuffer[mCount] = 0;
    }

    template <typename... Args>
    inline String(const char *aFmt, Args... aArgs) : mCount(0) {
        snprintf(mBuffer, STRING_SIZE, aFmt, aArgs...);
        mCount = (u8) strlen(mBuffer);
        mBuffer[mCount] = 0;
    }

    inline String(const String &aOther) : mCount(0) {
        mCount = aOther.mCount;
        memcpy(mBuffer, aOther.mBuffer, mCount);
        mBuffer[mCount] = 0;
    }

    inline void operator=(const String &aOther) {
        mCount = aOther.mCount;
        memcpy(mBuffer, aOther.mBuffer, mCount);
        mBuffer[mCount] = 0;
    }

public:
    void Add(char aChar) {
        if (mCount == STRING_SIZE - 1) return;
        mBuffer[mCount++] = aChar;
        mBuffer[mCount] = 0;
    }

    void Remove(s32 aIndex) {
        memmove(mBuffer + aIndex, mBuffer + aIndex + 1, (mCount-- - aIndex - 1));
        mBuffer[mCount] = 0;
    }

    void RemoveAll() {
        mCount = 0;
        mBuffer[0] = 0;
    }

    void Clear() {
        mCount = 0;
        mBuffer[0] = 0;
    }

    s32 Find(char aChar, s32 aStart = 0) const {
        for (u8 i = (u8) aStart; i < mCount; ++i) {
            if (mBuffer[i] == aChar) {
                return (s32) i;
            }
        }
        return -1;
    }

    s32 Find(const char *aString, s32 aStart = 0) const {
        const char *_Ptr = strstr(mBuffer + aStart, aString);
        if (_Ptr) return (s32) (_Ptr - mBuffer);
        return -1;
    }

    s32 FindLast(char aChar) const {
        for (u8 i = mCount; i != 0; --i) {
            if (mBuffer[i - 1] == aChar) {
                return (s32) (i - 1);
            }
        }
        return -1;
    }

    String SubString(s32 aStart, s32 aCount = STRING_SIZE - 1) const {
        if (aStart >= mCount) return String();
        if (aCount < 0) aCount = STRING_SIZE - 1;
        aCount = MIN(aCount, mCount - aStart);
        String _String;
        _String.mCount = aCount;
        memcpy(_String.mBuffer, mBuffer + aStart, aCount);
        _String.mBuffer[aCount] = 0;
        return _String;
    }

public:
    inline const char *begin() const { return mBuffer; }
    inline const char *end() const { return mBuffer + mCount; }
    inline char *begin() { return mBuffer; }
    inline char *end() { return mBuffer + mCount; }

    inline const char &operator[](s32 aIndex) const { return mBuffer[aIndex]; }
    inline char &operator[](s32 aIndex) { return mBuffer[aIndex]; }

    inline s32 Length() const { return (s32) mCount; }
    inline bool Empty() const { return mCount == 0; }

public:
    bool operator==(const char *aString) const {
        if (strlen(aString) != mCount) return false;
        for (u8 i = 0; i != mCount; ++i) {
            if (aString[i] != mBuffer[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator==(const String &aOther) const {
        if (aOther.mCount != mCount) return false;
        for (u8 i = 0; i != mCount; ++i) {
            if (aOther.mBuffer[i] != mBuffer[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const char *aString) const {
        if (strlen(aString) != mCount) return true;
        for (u8 i = 0; i != mCount; ++i) {
            if (aString[i] != mBuffer[i]) {
                return true;
            }
        }
        return false;
    }

    bool operator!=(const String &aOther) const {
        if (aOther.mCount != mCount) return true;
        for (u8 i = 0; i != mCount; ++i) {
            if (aOther.mBuffer[i] != mBuffer[i]) {
                return true;
            }
        }
        return false;
    }

public:
    void Read(FILE *aFile) {
        fread(&mCount, sizeof(u8), 1, aFile);
        fread(mBuffer, sizeof(char), mCount, aFile);
        mBuffer[mCount] = 0;
    }

    void Write(FILE *aFile) const {
        fwrite(&mCount, sizeof(u8), 1, aFile);
        fwrite(mBuffer, sizeof(char), mCount, aFile);
    }

    s32 ParseInt() const {
        s32 i = 0;
        if (mBuffer[1] == 'x') {
            sscanf(mBuffer + 2, "%x", &i);
        } else {
            sscanf(mBuffer, "%d", &i);
        }
        return i;
    }

    f32 ParseFloat() const {
        f32 f = 0.f;
        sscanf(mBuffer, "%f", &f);
        return f;
    }

private:
    char mBuffer[STRING_SIZE];
    u8 mCount;
};
static_assert(sizeof(String) == (STRING_SIZE + 1), "sizeof(String) must be (STRING_SIZE + 1)");

//
// Types
//

template <typename U, typename V>
using Pair = std::pair<U, V>;

typedef std::string SysPath;

class NoCopy {
  protected:
    NoCopy() {}
    ~NoCopy() {}
  private:
    NoCopy(const NoCopy &) = delete;
    void operator=(const NoCopy &) = delete;
};

struct TexData : NoCopy {
    Array<u8> mPngData;
    Array<u8> mRawData;
    s32 mRawWidth  = -1;
    s32 mRawHeight = -1;
    s32 mRawFormat = -1;
    s32 mRawSize   = -1;
    bool mUploaded = false;
    void *mBind    = NULL;
};

struct AnimData : NoCopy {
    s16 mFlags = 0;
    s16 mUnk02 = 0;
    s16 mUnk04 = 0;
    s16 mUnk06 = 0;
    s16 mUnk08 = 0;
    Pair<String, s16> mUnk0A;
    Pair<String, Array<s16>> mValues;
    Pair<String, Array<u16>> mIndex;
    u32 mLength = 0;
};

template <typename T>
struct DataNode : NoCopy {
    String mName;
    T* mData = NULL;
    u32 mSize = 0;
    Array<String> mTokens;
    u64 mModelIdentifier = 0;
    u64 mLoadIndex = 0;
};
template <typename T>
using DataNodes = Array<DataNode<T>*>;

struct GfxDynCmd {
    Gfx* mData = NULL;
    u32 mOffset = 0;
    u8 mType = 0;
};

struct GfxContext {
    DataNode<TexData>* mCurrentTexture = NULL;
    DataNode<TexData>* mCurrentPalette = NULL;
    Gfx mMetalBits    = { 0, 0 };
    Gfx mCombineMode  = { 0, 0 };
    Gfx mSpTexture    = { 0, 0 };
    Gfx mTxLoadTile   = { 0, 0 };
    Gfx mTxRenderTile = { 0, 0 };
    Gfx mSetTileSize  = { 0, 0 };
};

template <typename T>
using AnimBuffer = Pair<String, Array<T>>;
struct GfxData : NoCopy {

    // Model data
    DataNodes<Lights1> mLights;
    DataNodes<TexData> mTextures;
    DataNodes<Vtx> mVertices;
    DataNodes<Gfx> mDisplayLists;
    DataNodes<GeoLayout> mGeoLayouts;
    Array<GfxDynCmd> mGfxDynCmds;

    // Animation data
    Array<AnimBuffer<s16> *> mAnimValues;
    Array<AnimBuffer<u16> *> mAnimIndices;
    DataNodes<AnimData> mAnimations;
    Array<Pair<String, void *>> mAnimationTable;

    // Current
    u64 mLoadIndex = 0;
    s32 mErrorCount = 0;
    u32 mModelIdentifier = 0;
    SysPath mPackFolder;
    Array<void *> mPointerList;
    GfxContext mGfxContext;
    Array<GfxContext> mGeoNodeStack;
};

struct ActorGfx {
    GfxData *mGfxData = NULL;
    GraphNode *mGraphNode = NULL;
    s32 mPackIndex = 0;
};

typedef Pair<String, const u8 *> Label;
struct DynosOption : NoCopy {
    String mName;
    String mConfigName; // Name used in sm64config.txt
    Label mLabel;
    Label mTitle; // Full caps label, displayed with colored font
    DynosOption *mPrev;
    DynosOption *mNext;
    DynosOption *mParent;
    bool mDynos; // true from create, false from convert
    u8 mType;

    // TOGGLE
    struct Toggle : NoCopy {
        bool *mTog;
    } mToggle;

    // CHOICE
    struct Choice : NoCopy {
        Array<Label> mChoices;
        s32 *mIndex;
    } mChoice;

    // SCROLL
    struct Scroll : NoCopy {
        s32 mMin;
        s32 mMax;
        s32 mStep;
        s32 *mValue;
    } mScroll;

    // BIND
    struct Bind : NoCopy {
        u32 mMask;
        u32 *mBinds;
        s32 mIndex;
    } mBind;

    // BUTTON
    struct Button : NoCopy {
        String mFuncName;
    } mButton;

    // SUBMENU
    struct Submenu : NoCopy {
        DynosOption *mChild;
        bool mEmpty;
    } mSubMenu;
};
typedef bool (*DynosLoopFunc)(DynosOption *, void *);

//
// Utils
//

template <typename T>
T* New(u64 aCount = 1llu) {
    T *_Ptr = (T *) calloc(aCount, sizeof(T));
    for (u64 i = 0; i != aCount; ++i) {
        new (_Ptr + i) T(); // Calls the constructor of type T at address (_Ptr + i)
    }
    return _Ptr;
}

template <typename T>
void Delete(T *& aPtr) {
    if (aPtr) aPtr->~T();
    free(aPtr);
    aPtr = NULL;
}

template <typename T>
T *CopyBytes(const T *aPtr, u64 aSize) {
    T *_Ptr = (T *) calloc(1, aSize);
    memcpy(_Ptr, aPtr, aSize);
    return _Ptr;
}

template <typename T = void>
Array<String> Split(const char *aBuffer, const String &aDelimiters, const String &aEndCharacters = {}, bool aHandleDoubleQuotedStrings = false) {
    Array<String> _Tokens;
    String _Token;
    bool _TreatSpaceAsChar = false;
    u64 _Length = strlen(aBuffer);
    for (u64 i = 0; i <= _Length; ++i) {
        if (i == _Length || aDelimiters.Find(aBuffer[i]) != -1) {
            if (aBuffer[i] == ' ' && _TreatSpaceAsChar) {
                _Token.Add(aBuffer[i]);
            } else {
                if (!_Token.Empty()) {
                    _Tokens.Add(_Token);
                    _Token.Clear();
                }
                if (aEndCharacters.Find(aBuffer[i]) != -1) {
                    break;
                }
            }
        } else {
            if (aBuffer[i] == '\"' && aHandleDoubleQuotedStrings) {
                _TreatSpaceAsChar = !_TreatSpaceAsChar;
            } else {
                _Token.Add(aBuffer[i]);
            }
        }
    }
    return _Tokens;
}

template <typename T>
T ReadBytes(FILE* aFile) {
    T _Item = { 0 };
    fread(&_Item, sizeof(T), 1, aFile);
    return _Item;
}

template <typename T>
void WriteBytes(FILE* aFile, const T& aItem) {
    fwrite(&aItem, sizeof(T), 1, aFile);
}

template <typename... Args>
void PrintNoNewLine(const char *aFmt, Args... aArgs) {
    printf(aFmt, aArgs...);
    fflush(stdout);
}

template <typename... Args>
void Print(const char *aFmt, Args... aArgs) {
    printf(aFmt, aArgs...);
    printf("\r\n");
    fflush(stdout);
}

#define PrintError(...) { \
    if (aGfxData->mErrorCount == 0) Print("  ERROR!"); \
    Print(__VA_ARGS__); \
    aGfxData->mErrorCount++; \
}

template <typename... Args>
SysPath fstring(const char *aFmt, Args... aArgs) {
    char buffer[1024];
    snprintf(buffer, 1024, aFmt, aArgs...);
    return SysPath(buffer);
}

// Wraps the static into a function, to call the constructor on first use
#define STATIC_STORAGE(type, name)                                                                     \
    static type &__##name() {                                                                          \
        static type s##name;                                                                           \
        return s##name;                                                                                \
    }

//
// Main
//

void               DynOS_AddRoutine                      (u8 aType, void *aRoutine);
void               DynOS_Init                            ();
void               DynOS_UpdateOpt                       (void *aPad);
void              *DynOS_UpdateCmd                       (void *aCmd);
void               DynOS_UpdateGfx                       ();

//
// Opt
//

s32                DynOS_Opt_GetValue                    (const String &aName);
void               DynOS_Opt_SetValue                    (const String &aName, s32 aValue);
void               DynOS_Opt_AddAction                   (const String &aFuncName, bool (*aFuncPtr)(const char *), bool aOverwrite);
void               DynOS_Opt_Init                        ();
void               DynOS_Opt_InitVanilla                 (DynosOption *&aOptionsMenu);
void               DynOS_Opt_Update                      (OSContPad *aPad);
bool               DynOS_Opt_ControllerUpdate            (DynosOption *aOpt, void *aData);
s32                DynOS_Opt_ControllerGetKeyPressed     ();
void               DynOS_Opt_LoadConfig                  (DynosOption *aMenu);
void               DynOS_Opt_SaveConfig                  (DynosOption *aMenu);
void               DynOS_Opt_DrawMenu                    (DynosOption *aCurrentOption, DynosOption *aCurrentMenu, DynosOption *aOptionsMenu, DynosOption *aDynosMenu);
void               DynOS_Opt_DrawPrompt                  (DynosOption *aCurrentMenu, DynosOption *aOptionsMenu, DynosOption *aDynosMenu);

//
// Conversion
//

u8                *RGBA16_RGBA32                         (const u8 *aData, u64 aLength);
u8                *RGBA32_RGBA32                         (const u8 *aData, u64 aLength);
u8                *IA4_RGBA32                            (const u8 *aData, u64 aLength);
u8                *IA8_RGBA32                            (const u8 *aData, u64 aLength);
u8                *IA16_RGBA32                           (const u8 *aData, u64 aLength);
u8                *CI4_RGBA32                            (const u8 *aData, u64 aLength, const u8 *aPalette);
u8                *CI8_RGBA32                            (const u8 *aData, u64 aLength, const u8 *aPalette);
u8                *I4_RGBA32                             (const u8 *aData, u64 aLength);
u8                *I8_RGBA32                             (const u8 *aData, u64 aLength);
u8                *ConvertToRGBA32                       (const u8 *aData, u64 aLength, s32 aFormat, s32 aSize, const u8 *aPalette);

//
// Gfx
//

bool               DynOS_Gfx_IsLoadedTexturePointer      (void *aPtr);
bool               DynOS_Gfx_IsTexturePointer            (void *aPtr);
DataNode<TexData> *DynOS_Gfx_GetTexture                  (const String &aTextureName);
DataNode<TexData> *DynOS_Gfx_LoadTextureRaw              (const u8 *aRGBA32Buffer, s32 aWidth, s32 aHeight, const String &aTextureName);
DataNode<TexData> *DynOS_Gfx_LoadTexturePng              (const u8 *aPngData, u32 aPngLength, const String &aTextureName);
DataNode<TexData> *DynOS_Gfx_LoadTextureFile             (const SysPath &aFilename, const String &aTextureName);
void               DynOS_Gfx_BindTexture                 (DataNode<TexData> *aNode, void *aBind);
void               DynOS_Gfx_UnloadTexture               (DataNode<TexData> *aNode);
bool               DynOS_Gfx_ImportTexture               (void **aOutput, void *aPtr, s32 aTile, void *aGfxRApi, void **aHashMap, void *aPool, u32 *aPoolPos, u32 aPoolSize);
Array<ActorGfx>   &DynOS_Gfx_GetActorList                ();
Array<SysPath>    &DynOS_Gfx_GetPackFolders              ();
Array<String>      DynOS_Gfx_Init                        ();
void               DynOS_Gfx_Update                      ();
void               DynOS_Gfx_SwapAnimations              (void *aPtr);
bool               DynOS_Gfx_IsCappyEyesDisplayList      (GfxData *aGfxData, const String &aNodeName);
void               DynOS_Gfx_PushDynCmd                  (GfxData *aGfxData, DataNode<Gfx> *aNode, Gfx *&aHead, u8 aCmd);
bool               DynOS_Gfx_WriteBinary                 (const SysPath &aOutputFilename, GfxData *aGfxData);
GfxData           *DynOS_Gfx_LoadFromBinary              (const SysPath &aFilename);
void               DynOS_Gfx_Free                        (GfxData *aGfxData);
void               DynOS_Gfx_GeneratePack                (const SysPath &aPackFolder);

//
// Audio
//

void               DynOS_Audio_Mix                       (u8 *aOutput, const u8 *aInput, s32 aLength, f32 aVolume, f32 aDistance);
bool               DynOS_Music_LoadRaw                   (const String &aName, const u8 *aData, s32 aLength, s32 aLoop, f32 aVolume);
bool               DynOS_Music_LoadWav                   (const String &aName, const SysPath &aFilename, s32 aLoop, f32 aVolume);
bool               DynOS_Music_LoadPresets               (const SysPath &aFilename, const SysPath &aFolder);
void               DynOS_Music_Play                      (const String &aName);
void               DynOS_Music_Multi_Play                (const String &aName);
void               DynOS_Music_Stop                      ();
void               DynOS_Music_Pause                     ();
void               DynOS_Music_Resume                    ();
bool               DynOS_Music_IsPlaying                 (const String &aName);
bool               DynOS_Sound_LoadRaw                   (const String &aName, u8 aBank, const u8 *aData, s32 aLength, f32 aVolume, u8 aPriority);
bool               DynOS_Sound_LoadWav                   (const String &aName, u8 aBank, const SysPath &aFilename, f32 aVolume, u8 aPriority);
bool               DynOS_Sound_LoadPresets               (const SysPath &aFilename, const SysPath &aFolder);
void               DynOS_Sound_Play                      (const String &aName, f32 *aPos);
void               DynOS_Sound_Stop                      (u8 aBank);
bool               DynOS_Sound_IsPlaying                 (const String &aName);
bool               DynOS_Sound_IsPlaying                 (u8 aBank);
bool               DynOS_Jingle_LoadRaw                  (const String &aName, const u8 *aData, s32 aLength, s32 aLoop, f32 aVolume);
bool               DynOS_Jingle_LoadWav                  (const String &aName, const SysPath &aFilename, s32 aLoop, f32 aVolume);
bool               DynOS_Jingle_LoadPresets              (const SysPath &aFilename, const SysPath &aFolder);
void               DynOS_Jingle_Play                     (const String &aName);
void               DynOS_Jingle_Stop                     ();
void               DynOS_Jingle_Pause                    ();
void               DynOS_Jingle_Resume                   ();
bool               DynOS_Jingle_IsPlaying                (const String &aName);

//
// String
//

u8                *DynOS_String_Convert                  (const char *aString, bool aHeapAlloc);
u8                *DynOS_String_Decapitalize             (u8 *aStr64);
s32                DynOS_String_Length                   (const u8 *aStr64);
s32                DynOS_String_WidthChar64              (u8 aChar64);
s32                DynOS_String_Width                    (const u8 *aStr64);

//
// Geo
//

s32                DynOS_Geo_GetActorCount               ();
const char        *DynOS_Geo_GetActorName                (s32 aIndex);
void              *DynOS_Geo_GetActorLayout              (s32 aIndex);
s32                DynOS_Geo_GetActorIndex               (const void *aGeoLayout);
void              *DynOS_Geo_GetFunctionPointerFromName  (const String &aName);
void              *DynOS_Geo_GetFunctionPointerFromIndex (s32 aIndex);
s32                DynOS_Geo_GetFunctionIndex            (const void *aPtr);
void              *DynOS_Geo_GetGraphNode                (const void *aGeoLayout, bool aKeepInMemory);
void              *DynOS_Geo_SpawnObject                 (const void *aGeoLayout, void *aParent, const void *aBehavior);

//
// Levels
//

s32                DynOS_Level_GetCount                  ();
const s32         *DynOS_Level_GetList                   ();
s32                DynOS_Level_GetCourse                 (s32 aLevel);
const void        *DynOS_Level_GetScript                 (s32 aLevel);
const u8          *DynOS_Level_GetName                   (s32 aLevel, bool aDecaps, bool aAddCourseNumber);
const u8          *DynOS_Level_GetActName                (s32 aLevel, s32 aAct, bool aDecaps, bool aAddStarNumber);
s16               *DynOS_Level_GetWarp                   (s32 aLevel, s32 aArea, u8 aWarpId);
s16               *DynOS_Level_GetWarpEntry              (s32 aLevel, s32 aArea);
s16               *DynOS_Level_GetWarpStarCollect        (s32 aLevel, s32 aArea);
s16               *DynOS_Level_GetWarpDeath              (s32 aLevel, s32 aArea);
u64                DynOS_Level_CmdGet                    (void *aCmd, u64 aOffset);
void              *DynOS_Level_CmdNext                   (void *aCmd, u64 aCmdSize);
void               DynOS_Level_ParseScript               (const void *aScript, s32 (*aPreprocessFunction)(u8, void *));

//
// Warps
//

void              *DynOS_Warp_Update                     (void *aCmd, bool aIsLevelInitDone);
bool               DynOS_Warp_ToLevel                    (s32 aLevel, s32 aArea, s32 aAct);
bool               DynOS_Warp_RestartLevel               ();
bool               DynOS_Warp_ExitLevel                  (s32 aDelay);
bool               DynOS_Warp_ToCastle                   (s32 aLevel);
bool               DynOS_Warp_ReturnToMainMenu           ();
void               DynOS_Warp_SetParam                   (s32 aLevel, s32 aIndex);
const char        *DynOS_Warp_GetParamName               (s32 aLevel, s32 aIndex);

#endif
#endif
