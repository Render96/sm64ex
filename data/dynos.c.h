#ifndef DYNOS_C_H
#define DYNOS_C_H
#ifndef __cplusplus

#include "dynos.h"

inline static void *make_copy(const void *p, u64 s) {
    void *q = calloc(1, s);
    memcpy(q, p, s);
    return q;
}

#define va_string(str, size, fmt, ...)  char str[size]; snprintf(str, size, fmt, __VA_ARGS__);
#define str_eq(str1, str2)              (strcmp(str1, str2) == 0)

#define DYNOS_COURSE_NO_WARP(level)                 (dynos_level_get_course(level) == COURSE_NONE)
#define DYNOS_SANITY_CHECK(type, value, failsafe)   if (!dynos_sanity_check_##type(value)) { failsafe; }

// The action signature is "bool (*) (const char *)"
// The input is the button internal name (not label)
// The output is the result of the action
#define DYNOS_DEFINE_ACTION(func) \
AT_STARTUP static void dynos_opt_add_action_##func() { \
    dynos_opt_add_action(#func, func, false); \
}

//
// Dynamic Array
//

void *__da_do(s32, void **, s32, void *, bool (*eq)(void *, void *));

#define DynArray                                   void *
#define da_new(type)                             ((void *) __da_do(0, NULL, (s32) sizeof(type), NULL, NULL))
#define da_delete(da)                            ((void) __da_do(1, &(da), 0, NULL, NULL))
#define da_count(da)                             ((s32) (u64) __da_do(2, &(da), 0, NULL, NULL))
#define da_add(da, item)                         ((void) __da_do(3, &(da), 0, (void *) &(item), NULL))
#define da_rem(da, index)                        ((void) __da_do(4, &(da), (s32) index, NULL, NULL))
#define da_rem_all(da)                           ((void) __da_do(4, &(da), -1, NULL, NULL))
#define da_get(da, type, index)                (*((type *) __da_do(5, &(da), (s32) (index), NULL, NULL)))
#define da_getp(da, type, index)                 ((type *) __da_do(5, &(da), (s32) (index), NULL, NULL))
#define da_set(da, item, index)                  ((void) __da_do(6, &(da), (s32) (index), (void *) &(item), NULL))
#define da_find(da, item)                        ((s32) (u64) __da_do(7, &(da), 0, (void *) &(item), NULL))
#define da_find_eq(da, item, eq)                 ((s32) (u64) __da_do(7, &(da), 0, (void *) &(item), (void *) eq))
#define da_cast(type, item)                    (*((type *) (item)))
#define da_add_inplace(da, type, item)           { type __inplace = item; da_add(da, __inplace); }
#define da_set_inplace(da, type, item, index)    { type __inplace = item; da_set(da, __inplace, index); }

//
// Main
//

void        dynos_add_routine                          (u8 type, void *routine);
void       *dynos_update_cmd                           (void *cmd);
void        dynos_update_gfx                           ();

//
// Opt
//

s32         dynos_opt_get_value                        (const char *name);
void        dynos_opt_set_value                        (const char *name, s32 value);
void        dynos_opt_add_action                       (const char *funcname, bool (*funcptr)(const char *), bool overwrite);

//
// Conversion
//

u8         *rgba16_to_rgba32                           (const u8 *data, u64 length);
u8         *rgba32_to_rgba32                           (const u8 *data, u64 length);
u8         *ia4_to_rgba32                              (const u8 *data, u64 length);
u8         *ia8_to_rgba32                              (const u8 *data, u64 length);
u8         *ia16_to_rgba32                             (const u8 *data, u64 length);
u8         *ci4_to_rgba32                              (const u8 *data, u64 length, const u8 *palette);
u8         *ci8_to_rgba32                              (const u8 *data, u64 length, const u8 *palette);
u8         *i4_to_rgba32                               (const u8 *data, u64 length);
u8         *i8_to_rgba32                               (const u8 *data, u64 length);
u8         *convert_to_rgba32                          (const u8 *data, u64 length, s32 format, s32 size, const u8 *palette);

//
// Gfx
//

bool        dynos_gfx_is_loaded_texture_pointer        (void *ptr);
bool        dynos_gfx_is_texture_pointer               (void *ptr);
u8         *dynos_gfx_get_texture_data                 (void *ptr, s32 *width, s32 *height);
void       *dynos_gfx_get_texture                      (const char *texname);
void       *dynos_gfx_load_texture_raw                 (const u8 *rgba32buffer, s32 width, s32 height, const char *texname);
void       *dynos_gfx_load_texture_png                 (const u8 *pngdata, u32 pnglength, const char *texname);
void       *dynos_gfx_load_texture_file                (const char *filename, const char *texname);
void       *dynos_gfx_load_texture_from_dynos_folder   (const char *texname);
void        dynos_gfx_bind_texture                     (void *node, void *bind);
void        dynos_gfx_unload_texture                   (void *node);
s32         dynos_gfx_import_texture                   (void **output, void *ptr, s32 tile, void *grapi, void **hashmap, void *pool, s32 *poolpos, s32 poolsize);
void        dynos_gfx_swap_animations                  (void *ptr);

//
// Audio
//

void        dynos_audio_mix                            (u8 *output, const u8 *input, s32 length, f32 volume, f32 distance);
bool        dynos_music_load_raw                       (const char *name, const u8 *data, s32 length, s32 loop, f32 volume);
bool        dynos_music_load_wav                       (const char *name, const char *filename, s32 loop, f32 volume);
bool        dynos_music_load_from_dynos_folder         (const char *name, s32 loop, f32 volume);
bool        dynos_music_load_from_r96_folder           (const char *name, s32 loop, f32 volume);
bool        dynos_music_load_presets                   (const char *filename, const char *folder);
bool        dynos_music_load_presets_from_dynos_folder (const char *filename, const char *folder);
void        dynos_music_play                           (const char *name);
void        dynos_music_multi_play                     (const char *name);
void        dynos_music_stop                           ();
void        dynos_music_pause                          ();
void        dynos_music_resume                         ();
bool        dynos_music_is_playing                     (const char *name);
bool        dynos_sound_load_raw                       (const char *name, u8 bank, const u8 *data, s32 length, f32 volume, u8 priority);
bool        dynos_sound_load_wav                       (const char *name, u8 bank, const char *filename, f32 volume, u8 priority);
bool        dynos_sound_load_from_dynos_folder         (const char *name, u8 bank, f32 volume, u8 priority);
bool        dynos_sound_load_presets                   (const char *filename, const char *folder);
bool        dynos_sound_load_presets_from_dynos_folder (const char *filename, const char *folder);
void        dynos_sound_play                           (const char *name, f32 *pos);
void        dynos_sound_stop                           (u8 bank);
bool        dynos_sound_is_playing                     (const char *name);
bool        dynos_sound_is_bank_playing                (u8 bank);
bool        dynos_jingle_load_from_jingles_folder      (const char *name, s32 loop, f32 volume);
void        dynos_jingle_play                          (const char *name);
void        dynos_jingle_stop                          ();
void        dynos_jingle_pause                         ();
void        dynos_jingle_resume                        ();
bool        dynos_jingle_is_playing                    (const char *name);
bool        dynos_jingle_load_presets_from_dynos_folder (const char *filename, const char *folder);

//
// String
//

u8         *dynos_string_convert                       (const char *str, bool heap);
u8         *dynos_string_decapitalize                  (u8 *str64);
s32         dynos_string_length                        (const u8 *str64);
s32         dynos_string_cwidth                        (u8 c64);
s32         dynos_string_width                         (const u8 *str64);

//
// Geo
//

s32         dynos_geo_get_actor_count                  ();
const char *dynos_geo_get_actor_name                   (s32 index);
void       *dynos_geo_get_actor_layout                 (s32 index);
s32         dynos_geo_get_actor_index                  (const void *geolayout);
void       *dynos_geo_get_function_pointer_from_name   (const char *name);
void       *dynos_geo_get_function_pointer_from_index  (s32 index);
s32         dynos_geo_get_function_index               (const void *ptr);
void       *dynos_geo_get_graph_node                   (const void *geolayout, bool keepInMemory);
void       *dynos_geo_spawn_object                     (const void *geolayout, void *parent, const void *behavior);

//
// Levels
//

s32         dynos_level_get_count                      ();
const s32  *dynos_level_get_list                       ();
s32         dynos_level_get_course                     (s32 level);
const void *dynos_level_get_script                     (s32 level);
const u8   *dynos_level_get_name                       (s32 level, bool decaps, bool addCourseNumber);
const u8   *dynos_level_get_act_name                   (s32 level, s32 act, bool decaps, bool addStarNumber);
s16        *dynos_level_get_warp                       (s32 level, s32 area, u8 warpId);
s16        *dynos_level_get_warp_entry                 (s32 level, s32 area);
s16        *dynos_level_get_warp_star_collect          (s32 level, s32 area);
s16        *dynos_level_get_warp_death                 (s32 level, s32 area);
u64         dynos_level_cmd_get                        (void *cmd, u64 offset);
void       *dynos_level_cmd_next                       (void *cmd, u64 size);
void        dynos_level_parse_script                   (const void *script, s32 (*func)(u8, void *));

//
// Warps
//

bool        dynos_warp_to_level                        (s32 level, s32 area, s32 act);
bool        dynos_warp_restart_level                   ();
bool        dynos_warp_exit_level                      (s32 delay);
bool        dynos_warp_to_castle                       (s32 level);
bool        dynos_warp_return_to_main_menu             ();

//
// Sanity checks
//

bool        dynos_sanity_check_geo                     (s16 graphNodeType);
bool        dynos_sanity_check_seq                     (u8 loBits);
bool        dynos_sanity_check_vtx                     (const Vtx *vertices);

#endif
#endif
