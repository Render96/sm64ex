#ifndef R96_SYSTEM_H
#define R96_SYSTEM_H

#include "data/dynos.c.h"
#include "game/camera.h"
#include "include/types.h"

/* Character Swap */
void set_notification_status(s8 newState);
s8 get_notification_status();

s32 getCharacterType();
void setCharacterModel(s32 type);
f32 getCharacterMultiplier();
void triggerLuigiNotification();
//Todo: To be removed
s32 isLuigi();
s32 isWario();


/* Audio */

extern float softenVolume;
extern float softenJingleVolume;

// Infinite stairs

void r96_play_infinite_stairs_music();

// Action Functions

void r96_play_action_sound(struct MarioState *m, s32 actionSound);

// Character Functions

void r96_play_character_sound_if_no_flag(struct MarioState *m, const char* R96_MARIO, const char* R96_LUIGI, const char* R96_WARIO, u32 flags);
void r96_play_character_sound(struct MarioState *m, const char* R96_MARIO, const char* R96_LUIGI, const char* R96_WARIO);
void r96_play_character_sound_no_arg(const char* R96_MARIO, const char* R96_LUIGI, const char* R96_WARIO);
void r96_play_far_fall_sound(struct MarioState *m);
void r96_play_knockback_sound(struct MarioState *m);
void r96_play_character_charge_sound(struct MarioState *m);
void r96_play_character_jump_sound(struct MarioState *m);
void r96_play_character_flying_sound(struct MarioState *m);

// Shell Functions

void r96_play_shell_music();
void r96_stop_shell_music();

// Cap Functions

void r96_play_cap_music(const char* R96_CAP_MUSIC);
void r96_fadeout_cap_music();
void r96_stop_cap_music();
void r96_cap_music_boss_fix();

// Jingle Functions

void r96_play_menu_jingle(const char* R96_JINGLE);
void r96_play_jingle(const char* R96_JINGLE);
void r96_play_collect_jingle(const char* R96_JINGLE);
void r96_stop_jingle();
void r96_jingle_fade_out();

// Music Functions

void r96_play_music(const char* R96_MUSIC);
void r96_stop_music();

// When the fanfare is playing and the pause window opens
void r96_lower_music();

const char *r96_get_intended_level_music();
void r96_level_music_update();

#endif // R96_SYSTEM_H
