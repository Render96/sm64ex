#include "dynos.cpp.h"
extern "C" {

//
// C dynamic array, vector-like struct
//

typedef struct __DynArrayHeader {
    s32 size;
    s32 count;
    s32 capacity;
} __DynArrayHeader;

#define da                   (*dah)
#define buffer_at(index)     ((void *) ((u64) da + sizeof(__DynArrayHeader) + ((u64) da->size * (u64) (index))))

void *__da_do(s32 func, void **pda, s32 index, void *item, bool (*eq)(void *, void *)) {
    __DynArrayHeader **dah = (__DynArrayHeader **) pda;
    switch (func) {
        case 0: { // new
            void *p; dah = (__DynArrayHeader **) &p;
            da = (__DynArrayHeader *) calloc(1, sizeof(__DynArrayHeader) + 4 * index);
            da->size = index;
            da->count = 0;
            da->capacity = 4;
            return (void *) da;
        } break;

        case 1: { // delete
            if (da) {
                free(da);
                da = NULL;
            }
        } break;

        case 2: { // count
            if (da) {
                return (void *) (u64) (da->count);
            }
            return (void *) (u64) (0);
        } break;

        case 3: { // add
            if (da) {
                if (da->count == da->capacity) {
                    s32 _size = da->size;
                    s32 _count = da->count;
                    s32 _capacity = da->capacity;
                    void *p = calloc(1, sizeof(__DynArrayHeader) + _capacity * 2 * _size);
                    memcpy(p, da, sizeof(__DynArrayHeader) + _count * _size);
                    free(da);
                    da = (__DynArrayHeader *) p;
                    da->size = _size;
                    da->count = _count;
                    da->capacity = _capacity * 2;
                }
                memcpy(buffer_at(da->count), item, da->size);
                da->count += 1;
            }
        } break;

        case 4: { // rem
            if (da) {
                if (index == -1) {
                    da->count = 0;
                } else {
                    memmove(buffer_at(index), buffer_at(index + 1), (da->count - index - 1) * da->size);
                    da->count -= 1;
                }
            }
        } break;

        case 5: { // get
            if (da) {
                return buffer_at(index);
            }
        } break;

        case 6: { // set
            if (da) {
                memcpy(buffer_at(index), item, da->size);
            }
        } break;

        case 7: { // find
            if (da) {
                void *cur = buffer_at(0);
                void *end = buffer_at(da->count);
                if (eq) {
                    for (s32 i = 0; cur < end; i++, cur = (void *) ((u64) cur + (u64) da->size)) {
                        if (eq && eq(cur, item)) {
                            return (void *) (u64) (i);
                        }
                    }
                } else {
                    for (s32 i = 0; cur < end; i++, cur = (void *) ((u64) cur + (u64) da->size)) {
                        if (memcmp(cur, item, da->size) == 0) {
                            return (void *) (u64) (i);
                        }
                    }
                }
            }
            return (void *) (u64) (-1);
        } break;
    }
    return NULL;
}

#undef da
#undef buffer_at

//
// C++ to C wrappers
//

//
// Main
//

void dynos_add_routine(u8 type, void *routine) {
    return DynOS_AddRoutine(type, routine);
}

void *dynos_update_cmd(void *cmd) {
    return DynOS_UpdateCmd(cmd);
}

void dynos_update_gfx() {
    return DynOS_UpdateGfx();
}

//
// Opt
//

s32 dynos_opt_get_value(const char *name) {
    return DynOS_Opt_GetValue(name);
}

void dynos_opt_set_value(const char *name, s32 value) {
    return DynOS_Opt_SetValue(name, value);
}

void dynos_opt_add_action(const char *funcname, bool (*funcptr)(const char *), bool overwrite) {
    return DynOS_Opt_AddAction(funcname, funcptr, overwrite);
}

//
// Conversion
//

u8 *rgba16_to_rgba32(const u8 *data, u64 length) {
    return RGBA16_RGBA32(data, length);
}

u8 *rgba32_to_rgba32(const u8 *data, u64 length) {
    return RGBA32_RGBA32(data, length);
}

u8 *ia4_to_rgba32(const u8 *data, u64 length) {
    return IA4_RGBA32(data, length);
}

u8 *ia8_to_rgba32(const u8 *data, u64 length) {
    return IA8_RGBA32(data, length);
}

u8 *ia16_to_rgba32(const u8 *data, u64 length) {
    return IA16_RGBA32(data, length);
}

u8 *ci4_to_rgba32(const u8 *data, u64 length, const u8 *palette) {
    return CI4_RGBA32(data, length, palette);
}

u8 *ci8_to_rgba32(const u8 *data, u64 length, const u8 *palette) {
    return CI8_RGBA32(data, length, palette);
}

u8 *i4_to_rgba32(const u8 *data, u64 length) {
    return I4_RGBA32(data, length);
}

u8 *i8_to_rgba32(const u8 *data, u64 length) {
    return I8_RGBA32(data, length);
}

u8 *convert_to_rgba32(const u8 *data, u64 length, s32 format, s32 size, const u8 *palette) {
    return ConvertToRGBA32(data, length, format, size, palette);
}

//
// Gfx
//

bool dynos_gfx_is_loaded_texture_pointer(void *ptr) {
    return DynOS_Gfx_IsLoadedTexturePointer(ptr);
}

bool dynos_gfx_is_texture_pointer(void *ptr) {
    return DynOS_Gfx_IsTexturePointer(ptr);
}

u8 *dynos_gfx_get_texture_data(void *ptr, s32 *width, s32 *height) {
    if (ptr) {
        DataNode<TexData> *_Node = (DataNode<TexData> *) ptr;
        *width = _Node->mData->mRawWidth;
        *height = _Node->mData->mRawHeight;
        return _Node->mData->mRawData.begin();
    }
    return NULL;
}

void *dynos_gfx_get_texture(const char *texname) {
    return (void *) DynOS_Gfx_GetTexture(texname);
}

void *dynos_gfx_load_texture_raw(const u8 *rgba32buffer, s32 width, s32 height, const char *texname) {
    return (void *) DynOS_Gfx_LoadTextureRaw(rgba32buffer, width, height, texname);
}

void *dynos_gfx_load_texture_png(const u8 *pngdata, u32 pnglength, const char *texname) {
    return (void *) DynOS_Gfx_LoadTexturePng(pngdata, pnglength, texname);
}

void *dynos_gfx_load_texture_file(const char *filename, const char *texname) {
    return (void *) DynOS_Gfx_LoadTextureFile(filename, texname);
}

void *dynos_gfx_load_texture_from_dynos_folder(const char *texname) {
    char filename[256];
    snprintf(filename, 256, "%s/%s/%s.png", DYNOS_EXE_FOLDER, DYNOS_GFX_FOLDER, texname);
    return (void *) DynOS_Gfx_LoadTextureFile(filename, texname);
}

void dynos_gfx_bind_texture(void *node, void *bind) {
    return DynOS_Gfx_BindTexture((DataNode<TexData> *) node, bind);
}

void dynos_gfx_unload_texture(void *node) {
    return DynOS_Gfx_UnloadTexture((DataNode<TexData> *) node);
}

s32 dynos_gfx_import_texture(void **output, void *ptr, s32 tile, void *grapi, void **hashmap, void *pool, s32 *poolpos, s32 poolsize) {
    return DynOS_Gfx_ImportTexture(output, ptr, tile, grapi, hashmap, pool, (u32 *) poolpos, (u32) poolsize);
}

void dynos_gfx_swap_animations(void *ptr) {
    return DynOS_Gfx_SwapAnimations(ptr);
}

//
// Audio
//

void dynos_audio_mix(u8 *output, const u8 *input, s32 length, f32 volume, f32 distance) {
    return DynOS_Audio_Mix(output, input, length, volume, distance);
}

bool dynos_music_load_raw(const char *name, const u8 *data, s32 length, s32 loop, f32 volume) {
    return DynOS_Music_LoadRaw(name, data, length, loop, volume);
}

bool dynos_music_load_wav(const char *name, const char *filename, s32 loop, f32 volume) {
    return DynOS_Music_LoadWav(name, filename, loop, volume);
}

bool dynos_music_load_from_dynos_folder(const char *name, s32 loop, f32 volume) {
    char filename[256];
    snprintf(filename, 256, "%s/%s/%s.wav", DYNOS_EXE_FOLDER, DYNOS_AUDIO_FOLDER, name);
    return DynOS_Music_LoadWav(name, filename, loop, volume);
}

bool dynos_music_load_presets(const char *filename, const char *folder) {
    return DynOS_Music_LoadPresets(filename, folder);
}

bool dynos_music_load_presets_from_dynos_folder(const char *filename, const char *folder) {
    char filepath[256];
    char wavpath[256];
    snprintf(filepath, 256, "%s/%s/%s", DYNOS_EXE_FOLDER, DYNOS_AUDIO_FOLDER, filename);
    snprintf(wavpath, 256, "%s/%s/%s", DYNOS_EXE_FOLDER, DYNOS_AUDIO_FOLDER, folder);
    return DynOS_Music_LoadPresets(filepath, wavpath);
}

void dynos_music_play(const char *name) {
    return DynOS_Music_Play(name);
}

void dynos_music_multi_play(const char *name) {
    return DynOS_Music_Multi_Play(name);
}

void dynos_music_stop() {
    return DynOS_Music_Stop();
}

void dynos_music_pause() {
    return DynOS_Music_Pause();
}

void dynos_music_resume() {
    return DynOS_Music_Resume();
}

bool dynos_music_is_playing(const char *name) {
    return DynOS_Music_IsPlaying(name);
}

bool dynos_sound_load_raw(const char *name, u8 bank, const u8 *data, s32 length, f32 volume, u8 priority) {
    return DynOS_Sound_LoadRaw(name, bank, data, length, volume, priority);
}

bool dynos_sound_load_wav(const char *name, u8 bank, const char *filename, f32 volume, u8 priority) {
    return DynOS_Sound_LoadWav(name, bank, filename, volume, priority);
}

bool dynos_sound_load_from_dynos_folder(const char *name, u8 bank, f32 volume, u8 priority) {
    char filename[256];
    snprintf(filename, 256, "%s/%s/%s.wav", DYNOS_EXE_FOLDER, DYNOS_AUDIO_FOLDER, name);
    return DynOS_Sound_LoadWav(name, bank, filename, volume, priority);
}

bool dynos_sound_load_presets(const char *filename, const char *folder) {
    return DynOS_Sound_LoadPresets(filename, folder);
}

bool dynos_sound_load_presets_from_dynos_folder(const char *filename, const char *folder) {
    char filepath[256];
    char wavpath[256];
    snprintf(filepath, 256, "%s/%s/%s", DYNOS_EXE_FOLDER, DYNOS_AUDIO_FOLDER, filename);
    snprintf(wavpath, 256, "%s/%s/%s", DYNOS_EXE_FOLDER, DYNOS_AUDIO_FOLDER, folder);
    return DynOS_Sound_LoadPresets(filepath, wavpath);
}

void dynos_sound_play(const char *name, f32 *pos) {
    return DynOS_Sound_Play(name, pos);
}

void dynos_sound_stop(u8 bank) {
    return DynOS_Sound_Stop(bank);
}

bool dynos_sound_is_playing(const char *name) {
    return DynOS_Sound_IsPlaying(name);
}

bool dynos_sound_is_bank_playing(u8 bank) {
    return DynOS_Sound_IsPlaying(bank);
}

bool dynos_jingle_load_raw(const char *name, const u8 *data, s32 length, s32 loop, f32 volume) {
    return DynOS_Jingle_LoadRaw(name, data, length, loop, volume);
}

bool dynos_jingle_load_wav(const char *name, const char *filename, s32 loop, f32 volume) {
    return DynOS_Jingle_LoadWav(name, filename, loop, volume);
}

bool dynos_jingle_load_from_dynos_folder(const char *name, s32 loop, f32 volume) {
    char filename[256];
    snprintf(filename, 256, "%s/%s/%s.wav", DYNOS_EXE_FOLDER, DYNOS_AUDIO_FOLDER, name);
    return DynOS_Jingle_LoadWav(name, filename, loop, volume);
}

bool dynos_jingle_load_presets(const char *filename, const char *folder) {
    return DynOS_Jingle_LoadPresets(filename, folder);
}

bool dynos_jingle_load_presets_from_dynos_folder(const char *filename, const char *folder) {
    char filepath[256];
    char wavpath[256];
    snprintf(filepath, 256, "%s/%s/%s", DYNOS_EXE_FOLDER, DYNOS_AUDIO_FOLDER, filename);
    snprintf(wavpath, 256, "%s/%s/%s", DYNOS_EXE_FOLDER, DYNOS_AUDIO_FOLDER, folder);
    return DynOS_Jingle_LoadPresets(filepath, wavpath);
}

void dynos_jingle_play(const char *name) {
    return DynOS_Jingle_Play(name);
}

void dynos_jingle_stop() {
    return DynOS_Jingle_Stop();
}

void dynos_jingle_pause() {
    return DynOS_Jingle_Pause();
}

void dynos_jingle_resume() {
    return DynOS_Jingle_Resume();
}

bool dynos_jingle_is_playing(const char *name) {
    return DynOS_Jingle_IsPlaying(name);
}

//
// String
//

u8 *dynos_string_convert(const char *str, bool heap) {
    return DynOS_String_Convert(str, heap);
}

u8 *dynos_string_decapitalize(u8 *str64) {
    return DynOS_String_Decapitalize(str64);
}

s32 dynos_string_length(const u8 *str64) {
    return DynOS_String_Length(str64);
}

s32 dynos_string_cwidth(u8 c64) {
    return DynOS_String_WidthChar64(c64);
}

s32 dynos_string_width(const u8 *str64) {
    return DynOS_String_Width(str64);
}

//
// Geo
//

s32 dynos_geo_get_actor_count() {
    return DynOS_Geo_GetActorCount();
}

const char *dynos_geo_get_actor_name(s32 index) {
    return DynOS_Geo_GetActorName(index);
}

void *dynos_geo_get_actor_layout(s32 index) {
    return DynOS_Geo_GetActorLayout(index);
}

s32 dynos_geo_get_actor_index(const void *geolayout) {
    return DynOS_Geo_GetActorIndex(geolayout);
}

void *dynos_geo_get_function_pointer_from_name(const char *name) {
    return DynOS_Geo_GetFunctionPointerFromName(name);
}

void *dynos_geo_get_function_pointer_from_index(s32 index) {
    return DynOS_Geo_GetFunctionPointerFromIndex(index);
}

s32 dynos_geo_get_function_index(const void *ptr) {
    return DynOS_Geo_GetFunctionIndex(ptr);
}

void *dynos_geo_get_graph_node(const void *geolayout, bool keepInMemory) {
    return DynOS_Geo_GetGraphNode(geolayout, keepInMemory);
}

void *dynos_geo_spawn_object(const void *geolayout, void *parent, const void *behavior) {
    return DynOS_Geo_SpawnObject(geolayout, parent, behavior);
}

//
// Levels
//

s32 dynos_level_get_count() {
    return DynOS_Level_GetCount();
}

const s32 *dynos_level_get_list() {
    return DynOS_Level_GetList();
}

s32 dynos_level_get_course(s32 level) {
    return DynOS_Level_GetCourse(level);
}

const void *dynos_level_get_script(s32 level) {
    return DynOS_Level_GetScript(level);
}

const u8 *dynos_level_get_name(s32 level, bool decaps, bool addCourseNumber) {
    return DynOS_Level_GetName(level, decaps, addCourseNumber);
}

const u8 *dynos_level_get_act_name(s32 level, s32 act, bool decaps, bool addStarNumber) {
    return DynOS_Level_GetActName(level, act, decaps, addStarNumber);
}

u64 dynos_level_cmd_get(void *cmd, u64 offset) {
    return DynOS_Level_CmdGet(cmd, offset);
}

void *dynos_level_cmd_next(void *cmd, u64 size) {
    return DynOS_Level_CmdNext(cmd, size);
}

void dynos_level_parse_script(const void *script, s32 (*func)(u8, void *)) {
    return DynOS_Level_ParseScript(script, func);
}

s16 *dynos_level_get_warp(s32 level, s32 area, u8 warpId) {
    return DynOS_Level_GetWarp(level, area, warpId);
}

s16 *dynos_level_get_warp_entry(s32 level, s32 area) {
    return DynOS_Level_GetWarpEntry(level, area);
}

s16 *dynos_level_get_warp_star_collect(s32 level, s32 area) {
    return DynOS_Level_GetWarpStarCollect(level, area);
}

s16 *dynos_level_get_warp_death(s32 level, s32 area) {
    return DynOS_Level_GetWarpDeath(level, area);
}

//
// Warps
//

bool dynos_warp_to_level(s32 level, s32 area, s32 act) {
    return DynOS_Warp_ToLevel(level, area, act);
}

bool dynos_warp_restart_level() {
    return DynOS_Warp_RestartLevel();
}

bool dynos_warp_exit_level(s32 delay) {
    return DynOS_Warp_ExitLevel(delay);
}

bool dynos_warp_to_castle(s32 level) {
    return DynOS_Warp_ToCastle(level);
}

bool dynos_warp_return_to_main_menu() {
    return DynOS_Warp_ReturnToMainMenu();
}

}
