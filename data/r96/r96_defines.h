#ifndef R96_DEFINES_H
#define R96_DEFINES_H

/* Character Swap */
#define MARIO_DEFAULT 0
#define LUIGI 1
#define WARIO 2

/* Audio */

#define NO_MUSIC "EMPTY"

/* Music */
#define R96_LEVEL_BOB                             "level_bob" //SEQ_LEVEL_GRASS
#define R96_LEVEL_WF                              "level_wf" //SEQ_LEVEL_GRASS
#define R96_LEVEL_CCM                             "level_ccm" //SEQ_LEVEL_SNOW
#define R96_LEVEL_CCM_SLIDE                       "level_ccm_slide" //SEQ_LEVEL_SLIDE
#define R96_LEVEL_JRB_PHASE_1                     "level_jrb_phase_1" //SEQ_LEVEL_WATER
#define R96_LEVEL_JRB_PHASE_2                     "level_jrb_phase_2" //SEQ_LEVEL_WATER
#define R96_LEVEL_JRB_PHASE_3                     "level_jrb_phase_3" //SEQ_LEVEL_WATER
#define R96_LEVEL_JRB_SHIP                        "level_jrb_ship" //SEQ_LEVEL_WATER
#define R96_LEVEL_BBH_PHASE_1                     "level_bbh_phase_1" //SEQ_LEVEL_SPOOKY
#define R96_LEVEL_BBH_PHASE_2                     "level_bbh_phase_2" //SEQ_LEVEL_SPOOKY
#define R96_LEVEL_HMC_PHASE_1                     "level_hmc_phase_1" //SEQ_LEVEL_UNDERGROUND
#define R96_LEVEL_HMC_PHASE_2                     "level_hmc_phase_2" //SEQ_LEVEL_UNDERGROUND
#define R96_LEVEL_LLL_OUTSIDE                     "level_lll_outside" //SEQ_LEVEL_HOT
#define R96_LEVEL_LLL_VOLCANO                     "level_lll_volcano" //SEQ_LEVEL_HOT
#define R96_LEVEL_SSL_OUTSIDE                     "level_ssl_outside" //SEQ_LEVEL_HOT
#define R96_LEVEL_SSL_PYRAMID                     "level_ssl_pyramid" //SEQ_LEVEL_UNDERGROUND
#define R96_LEVEL_SSL_EYEROK                      "level_ssl_eyerok" //SEQ_LEVEL_UNDERGROUND
#define R96_LEVEL_DDD_PHASE_1                     "level_ddd_phase_1" //SEQ_LEVEL_WATER
#define R96_LEVEL_DDD_PHASE_2                     "level_ddd_phase_2" //SEQ_LEVEL_WATER
#define R96_LEVEL_DDD_PHASE_3                     "level_ddd_phase_3" //SEQ_LEVEL_WATER
#define R96_LEVEL_SL_OUTSIDE                      "level_sl_outside" //SEQ_LEVEL_SNOW
#define R96_LEVEL_SL_IGLOO                        "level_sl_igloo" //SEQ_LEVEL_UNDERGROUND
#define R96_LEVEL_WDW_MAIN                        "level_wdw_main" //SEQ_LEVEL_UNDERGROUND
#define R96_LEVEL_WDW_TOWN                        "level_wdw_town" //SEQ_LEVEL_UNDERGROUND
#define R96_LEVEL_TTM_OUTSIDE                     "level_ttm_outside" //SEQ_LEVEL_GRASS
#define R96_LEVEL_TTM_SLIDE                       "level_ttm_slide" //SEQ_LEVEL_SLIDE
#define R96_LEVEL_THI_HUGE                        "level_thi_huge" //SEQ_LEVEL_GRASS
#define R96_LEVEL_THI_TINY                        "level_thi_tiny" //SEQ_LEVEL_GRASS
#define R96_LEVEL_THI_WIGGLER                     "level_thi_wiggler" //SEQ_LEVEL_UNDERGROUND
#define R96_LEVEL_TTC                             "level_ttc" //SEQ_LEVEL_SLIDE
#define R96_LEVEL_RR                              "level_rr" //SEQ_LEVEL_SLIDE
#define R96_LEVEL_BITDW                           "level_bitdw" //SEQ_LEVEL_KOOPA_ROAD
#define R96_LEVEL_BITFS                           "level_bitfs" //SEQ_LEVEL_KOOPA_ROAD
#define R96_LEVEL_BITS                            "level_bits" //SEQ_LEVEL_KOOPA_ROAD
#define R96_LEVEL_SA                              "level_sa" //SEQ_LEVEL_WATER
#define R96_LEVEL_WMOTR                           "level_wmotr" //SEQ_LEVEL_SLIDE
#define R96_LEVEL_PSS                             "level_pss" //SEQ_LEVEL_SLIDE
#define R96_LEVEL_COTMC                           "level_cotmc" //SEQ_LEVEL_UNDERGROUND
#define R96_LEVEL_TOTWC                           "level_totwc" //SEQ_LEVEL_SLIDE
#define R96_LEVEL_VCUTM                           "level_vcutm" //SEQ_LEVEL_SLIDE
#define R96_LEVEL_BOWSER_1                        "level_bowser_1" //SEQ_LEVEL_BOSS_KOOPA
#define R96_LEVEL_BOWSER_2                        "level_bowser_2" //SEQ_LEVEL_BOSS_KOOPA
#define R96_LEVEL_BOWSER_3                        "level_bowser_3" //SEQ_LEVEL_BOSS_KOOPA_FINAL
#define R96_LEVEL_INSIDE_CASTLE_LOBBY             "level_inside_castle_lobby" //SEQ_LEVEL_INSIDE_CASTLE
#define R96_LEVEL_INSIDE_CASTLE_TIPPY             "level_inside_castle_tippy" //SEQ_LEVEL_INSIDE_CASTLE
#define R96_LEVEL_INSIDE_CASTLE_BASEMENT          "level_inside_castle_basement" //SEQ_LEVEL_INSIDE_CASTLE
#define R96_LEVEL_CASTLE_GROUNDS                  "level_castle_grounds"
#define R96_LEVEL_CASTLE_COURTYARD                "level_castle_courtyard"
#define R96_LEVEL_FOURTH_FLOOR                    "level_fourth_floor"

/* Jingle */
// loops
#define R96_EVENT_BOSS_INTRO                      "event_boss_intro"
#define R96_EVENT_BOSS_THEME                      "event_boss_theme" //SEQ_EVENT_BOSS
#define R96_EVENT_ENDLESS_STAIRS                  "event_endless_stairs" //SEQ_EVENT_ENDLESS_STAIRS
#define R96_EVENT_MERRY_GO_ROUND                  "event_merry_go_round" //SEQ_EVENT_MERRY_GO_ROUND
#define R96_EVENT_CAP_METAL                       "event_cap_metal" //SEQ_EVENT_METAL_CAP
#define R96_EVENT_RACE                            "event_race"
#define R96_EVENT_PIRANHA_PLANT                   "event_piranha_plant" //SEQ_EVENT_PIRANHA_PLANT
#define R96_MENU_FILE_SELECT                      "menu_file_select" //SEQ_MENU_FILE_SELECT
#define R96_EVENT_GOT_MILK                        "event_got_milk"
#define R96_EVENT_TITLE_SCREEN                    "event_title_screen"
#define R96_EVENT_CAP_VANISH                      "event_cap_vanish" //SEQ_EVENT_POWERUP
#define R96_EVENT_CAP_WING                        "event_cap_wing" //SEQ_EVENT_POWERUP
#define R96_EVENT_SHELL                           "event_shell" //SEQ_EVENT_POWERUP

//no loops
#define R96_EVENT_GAME_OVER                       "event_game_over"
#define R96_EVENT_KEY_COLLECT                     "event_key_collect" //SEQ_EVENT_CUTSCENE_COLLECT_KEY
#define R96_EVENT_PEACH_ENDING                    "event_peach_ending" //SEQ_EVENT_CUTSCENE_ENDING
#define R96_EVENT_PEACH_MESSAGE                   "event_peach_message" //SEQ_EVENT_PEACH_MESSAGE
#define R96_EVENT_RACE_FANFARE                    "event_race_fanfare" //SEQ_EVENT_RACE
#define R96_EVENT_SOLVE_PUZZLE                    "event_solve_puzzle" //SEQ_EVENT_SOLVE_PUZZLE
#define R96_EVENT_STAR_APPEAR                     "event_star_appear" //SEQ_EVENT_CUTSCENE_STAR_SPAWN
#define R96_EVENT_STAR_COLLECT                    "event_star_collect" //SEQ_EVENT_CUTSCENE_COLLECT_STAR
#define R96_EVENT_STAR_FANFARE                    "event_star_fanfare" //SEQ_EVENT_HIGH_SCORE
#define R96_EVENT_TOAD_MESSAGE                    "event_toad_message" //SEQ_EVENT_TOAD_MESSAGE
#define R96_EVENT_KOOPA_MESSAGE                   "event_koopa_message" //SEQ_EVENT_KOOPA_MESSAGE
#define R96_EVENT_INTRO                           "event_intro" //SEQ_EVENT_CUTSCENE_INTRO
#define R96_EVENT_CREDITS                         "event_credits" //SEQ_EVENT_CUTSCENE_CREDITS
#define R96_EVENT_LAKITU_MESSAGE                  "event_lakitu_message" //SEQ_EVENT_CUTSCENE_LAKITU
#define R96_EVENT_VICTORY                         "event_victory" //SEQ_EVENT_CUTSCENE_VICTORY
#define R96_EVENT_STAR_SELECT                     "event_star_select" //SEQ_MENU_STAR_SELECT
#define R96_EVENT_COLLECTIBLE_GRAB                "event_collectible_grab"

/* Sounds */
// sfx_mario
#define R96_MARIO_HOO                             "mario_hoo" //SOUND_MARIO_YAH_WAH_HOO
#define R96_MARIO_WAH                             "mario_wah"
#define R96_MARIO_YAH                             "mario_yah"
#define R96_MARIO_HAHA                            "mario_haha" //SOUND_MARIO_HAHA
#define R96_MARIO_YAHOO                           "mario_yahoo" //SOUND_MARIO_YAHOO
#define R96_MARIO_GRUNT                           "mario_grunt" //SOUND_MARIO_UH
#define R96_MARIO_LIFT                            "mario_lift" //SOUND_MARIO_HRMM
#define R96_MARIO_THROW                           "mario_throw" //SOUND_MARIO_WAH2
#define R96_MARIO_WHOA                            "mario_whoa" //SOUND_MARIO_WHOA
#define R96_MARIO_PULL_UP                         "mario_pull_up" //SOUND_MARIO_EEUH
#define R96_MARIO_ATTACKED                        "mario_attacked" //SOUND_MARIO_ATTACKED
#define R96_MARIO_OOOF                            "mario_ooof" //SOUND_MARIO_OOOF
#define R96_MARIO_HERE_WE_GO                      "mario_here_we_go" //SOUND_MARIO_HERE_WE_GO
#define R96_MARIO_YAWNING                         "mario_yawning" //SOUND_MARIO_YAWNING
#define R96_MARIO_SNORING_1                       "mario_snoring_1" //SOUND_MARIO_SNORING1
#define R96_MARIO_SNORING_2                       "mario_snoring_2" //SOUND_MARIO_SNORING2
#define R96_MARIO_DOH                             "mario_doh" //SOUND_MARIO_DOH
#define R96_MARIO_GAME_OVER                       "mario_game_over" //SOUND_MARIO_GAME_OVER
#define R96_MARIO_HELLO                           "mario_hello" //SOUND_MARIO_HELLO
#define R96_MARIO_PRESS_START_TO_PLAY             "mario_press_start_to_play" //SOUND_MARIO_PRESS_START_TO_PLAY
#define R96_MARIO_TWIRL_BOUNCE                    "mario_twirl_bounce" //SOUND_MARIO_TWIRL_BOUNCE
#define R96_MARIO_SNORING_3                       "mario_snoring_3" //SOUND_MARIO_SNORING3
#define R96_MARIO_SO_LONGA_BOWSER                 "mario_so_longa_bowser" //SOUND_MARIO_SO_LONGA_BOWSER
#define R96_MARIO_IMA_TIRED                       "mario_ima_tired" //SOUND_MARIO_IMA_TIRED
#define R96_MARIO_WAHA                            "mario_waha" //SOUND_MARIO_YAHOO_WAHA_YIPPEE
#define R96_MARIO_YIPPEE                          "mario_yippee"
#define R96_MARIO_SOUND_LETS_A_GO                 "mario_sound_lets_a_go" //SOUND_MENU_STAR_SOUND_LETS_A_GO
    
// sfx_mario_peach        
#define R96_MARIO_FALLING                         "mario_falling" //SOUND_MARIO_WAAAOOOW
#define R96_MARIO_HOOHOO                          "mario_hoohoo" //SOUND_MARIO_HOOHOO
#define R96_MARIO_PANTING                         "mario_panting" //SOUND_MARIO_PANTING
#define R96_MARIO_DYING                           "mario_dying" //SOUND_MARIO_DYING
#define R96_MARIO_ON_FIRE                         "mario_on_fire" //SOUND_MARIO_ON_FIRE
#define R96_MARIO_GRUNT_2                         "mario_grunt_2" //SOUND_MARIO_UH2_2
#define R96_MARIO_COUGHING_1                      "mario_coughing_1" //SOUND_MARIO_COUGHING1
#define R96_MARIO_ITS_A_ME_MARIO                  "mario_its_a_me_mario" //SOUND_MENU_COIN_ITS_A_ME_MARIO
#define R96_MARIO_PUNCH_YAH                       "mario_punch_yah" //SOUND_MARIO_PUNCH_YAH
#define R96_MARIO_PUNCH_HOO                       "mario_punch_hoo" //SOUND_MARIO_PUNCH_HOO
#define R96_MARIO_MAMA_MIA                        "mario_mama_mia" //SOUND_MARIO_MAMA_MIA
#define R96_MARIO_OKEY_DOKEY                      "mario_okey_dokey" //SOUND_MARIO_OKEY_DOKEY
#define R96_MARIO_DROWNING                        "mario_drowning" //SOUND_MARIO_DROWNING
#define R96_MARIO_THANK_YOU_PLAYING_MY_GAME       "mario_thank_you_playing_my_game" //SOUND_MENU_THANK_YOU_PLAYING_MY_GAME
#define R96_MARIO_PEACH_DEAR_MARIO                "mario_peach_dear_mario" //SOUND_PEACH_DEAR_MARIO
#define R96_MARIO_PEACH_MARIO                     "mario_peach_mario" //SOUND_PEACH_MARIO
#define R96_MARIO_PEACH_POWER_OF_THE_STARS        "mario_peach_power_of_the_stars" //SOUND_PEACH_POWER_OF_THE_STARS
#define R96_MARIO_PEACH_THANKS_TO_YOU             "mario_peach_thanks_to_you" //SOUND_PEACH_THANKS_TO_YOU
#define R96_MARIO_PEACH_THANK_YOU_MARIO           "mario_peach_thank_you_mario" //SOUND_PEACH_THANK_YOU_MARIO
#define R96_MARIO_PEACH_SOMETHING_SPECIAL         "mario_peach_something_special" //SOUND_PEACH_SOMETHING_SPECIAL
#define R96_MARIO_PEACH_BAKE_A_CAKE               "mario_peach_bake_a_cake" //SOUND_PEACH_BAKE_A_CAKE
#define R96_MARIO_PEACH_FOR_MARIO                 "mario_peach_for_mario" //SOUND_PEACH_FOR_MARIO
#define R96_MARIO_SOUND_PEACH_MARIO2              "mario_sound_peach_mario2" //SOUND_PEACH_MARIO2
#define R96_MARIO_PANTING_COLD                    "mario_panting_cold" //SOUND_MARIO_PANTING_COLD

// sfx_luigi
#define R96_LUIGI_HOO                             "luigi_hoo" //SOUND_LUIGI_YAH_WAH_HOO
#define R96_LUIGI_WAH                             "luigi_wah"
#define R96_LUIGI_YAH                             "luigi_yah"
#define R96_LUIGI_HAHA                            "luigi_haha" //SOUND_LUIGI_HAHA
#define R96_LUIGI_YAHOO                           "luigi_yahoo" //SOUND_LUIGI_YAHOO
#define R96_LUIGI_GRUNT                           "luigi_grunt" //SOUND_LUIGI_UH
#define R96_LUIGI_LIFT                            "luigi_lift" //SOUND_LUIGI_HRMM
#define R96_LUIGI_THROW                           "luigi_throw" //SOUND_LUIGI_WAH2
#define R96_LUIGI_WHOA                            "luigi_whoa" //SOUND_LUIGI_WHOA
#define R96_LUIGI_PULL_UP                         "luigi_pull_up" //SOUND_LUIGI_EEUH
#define R96_LUIGI_ATTACKED                        "luigi_attacked" //SOUND_LUIGI_ATTACKED
#define R96_LUIGI_OOOF                            "luigi_ooof" //SOUND_LUIGI_OOOF
#define R96_LUIGI_HERE_WE_GO                      "luigi_here_we_go" //SOUND_LUIGI_HERE_WE_GO
#define R96_LUIGI_YAWNING                         "luigi_yawning" //SOUND_LUIGI_YAWNING
#define R96_LUIGI_SNORING_1                       "luigi_snoring_1" //SOUND_LUIGI_SNORING1
#define R96_LUIGI_SNORING_2                       "luigi_snoring_2" //SOUND_LUIGI_SNORING2
#define R96_LUIGI_DOH                             "luigi_doh" //SOUND_LUIGI_DOH
#define R96_LUIGI_GAME_OVER                       "luigi_game_over" //SOUND_LUIGI_GAME_OVER
#define R96_LUIGI_HELLO                           "luigi_hello" //SOUND_LUIGI_HELLO
#define R96_LUIGI_PRESS_START_TO_PLAY             "luigi_press_start_to_play" //SOUND_LUIGI_PRESS_START_TO_PLAY
#define R96_LUIGI_TWIRL_BOUNCE                    "luigi_twirl_bounce" //SOUND_LUIGI_TWIRL_BOUNCE
#define R96_LUIGI_SNORING_3                       "luigi_snoring_3" //SOUND_LUIGI_SNORING3
#define R96_LUIGI_SO_LONGA_BOWSER                 "luigi_so_longa_bowser" //SOUND_LUIGI_SO_LONGA_BOWSER
#define R96_LUIGI_IMA_TIRED                       "luigi_ima_tired" //SOUND_LUIGI_IMA_TIRED
#define R96_LUIGI_WAHA                            "luigi_waha" //SOUND_LUIGI_YAHOO_WAHA_YIPPEE
#define R96_LUIGI_YIPPEE                          "luigi_yippee"
#define R96_LUIGI_SOUND_LETS_A_GO                 "luigi_sound_lets_a_go" //SOUND_MENU_STAR_SOUND_LETS_A_GO
    
// sfx_luigi_peach        
#define R96_LUIGI_FALLING                         "luigi_falling" //SOUND_LUIGI_WAAAOOOW
#define R96_LUIGI_HOOHOO                          "luigi_hoohoo" //SOUND_LUIGI_HOOHOO
#define R96_LUIGI_PANTING                         "luigi_panting" //SOUND_LUIGI_PANTING
#define R96_LUIGI_DYING                           "luigi_dying" //SOUND_LUIGI_DYING
#define R96_LUIGI_ON_FIRE                         "luigi_on_fire" //SOUND_LUIGI_ON_FIRE
#define R96_LUIGI_GRUNT_2                         "luigi_grunt_2" //SOUND_LUIGI_UH2_2
#define R96_LUIGI_COUGHING_1                      "luigi_coughing_1" //SOUND_LUIGI_COUGHING1
#define R96_LUIGI_ITS_A_ME_LUIGI                  "luigi_its_a_me_luigi" //SOUND_MENU_COIN_ITS_A_ME_LUIGI
#define R96_LUIGI_PUNCH_YAH                       "luigi_punch_yah" //SOUND_LUIGI_PUNCH_YAH
#define R96_LUIGI_PUNCH_HOO                       "luigi_punch_hoo" //SOUND_LUIGI_PUNCH_HOO
#define R96_LUIGI_MAMA_MIA                        "luigi_mama_mia" //SOUND_LUIGI_MAMA_MIA
#define R96_LUIGI_OKEY_DOKEY                      "luigi_okey_dokey" //SOUND_LUIGI_OKEY_DOKEY
#define R96_LUIGI_DROWNING                        "luigi_drowning" //SOUND_LUIGI_DROWNING
#define R96_LUIGI_THANK_YOU_PLAYING_MY_GAME       "luigi_thank_you_playing_my_game" //SOUND_MENU_THANK_YOU_PLAYING_MY_GAME
#define R96_LUIGI_PEACH_DEAR_LUIGI                "luigi_peach_dear_luigi" //SOUND_PEACH_DEAR_LUIGI
#define R96_LUIGI_PEACH_LUIGI                     "luigi_peach_luigi" //SOUND_PEACH_LUIGI
#define R96_LUIGI_PEACH_POWER_OF_THE_STARS        "luigi_peach_power_of_the_stars" //SOUND_PEACH_POWER_OF_THE_STARS
#define R96_LUIGI_PEACH_THANKS_TO_YOU             "luigi_peach_thanks_to_you" //SOUND_PEACH_THANKS_TO_YOU
#define R96_LUIGI_PEACH_THANK_YOU_LUIGI           "luigi_peach_thank_you_luigi" //SOUND_PEACH_THANK_YOU_LUIGI
#define R96_LUIGI_PEACH_SOMETHING_SPECIAL         "luigi_peach_something_special" //SOUND_PEACH_SOMETHING_SPECIAL
#define R96_LUIGI_PEACH_BAKE_A_CAKE               "luigi_peach_bake_a_cake" //SOUND_PEACH_BAKE_A_CAKE
#define R96_LUIGI_PEACH_FOR_LUIGI                 "luigi_peach_for_luigi" //SOUND_PEACH_FOR_LUIGI
#define R96_LUIGI_SOUND_PEACH_LUIGI2              "luigi_sound_peach_luigi2" //SOUND_PEACH_LUIGI2
#define R96_LUIGI_PANTING_COLD                    "luigi_panting_cold" //SOUND_LUIGI_PANTING_COLD

// sfx_wario
#define R96_WARIO_HOO                             "wario_hoo" //SOUND_WARIO_YAH_WAH_HOO
#define R96_WARIO_WAH                             "wario_wah"
#define R96_WARIO_YAH                             "wario_yah"
#define R96_WARIO_HAHA                            "wario_haha" //SOUND_WARIO_HAHA
#define R96_WARIO_YAHOO                           "wario_yahoo" //SOUND_WARIO_YAHOO
#define R96_WARIO_GRUNT                           "wario_grunt" //SOUND_WARIO_UH
#define R96_WARIO_LIFT                            "wario_lift" //SOUND_WARIO_HRMM
#define R96_WARIO_THROW                           "wario_throw" //SOUND_WARIO_WAH2
#define R96_WARIO_WHOA                            "wario_whoa" //SOUND_WARIO_WHOA
#define R96_WARIO_PULL_UP                         "wario_pull_up" //SOUND_WARIO_EEUH
#define R96_WARIO_ATTACKED                        "wario_attacked" //SOUND_WARIO_ATTACKED
#define R96_WARIO_OOOF                            "wario_ooof" //SOUND_WARIO_OOOF
#define R96_WARIO_HERE_WE_GO                      "wario_here_we_go" //SOUND_WARIO_HERE_WE_GO
#define R96_WARIO_YAWNING                         "wario_yawning" //SOUND_WARIO_YAWNING
#define R96_WARIO_SNORING_1                       "wario_snoring_1" //SOUND_WARIO_SNORING1
#define R96_WARIO_SNORING_2                       "wario_snoring_2" //SOUND_WARIO_SNORING2
#define R96_WARIO_DOH                             "wario_doh" //SOUND_WARIO_DOH
#define R96_WARIO_GAME_OVER                       "wario_game_over" //SOUND_WARIO_GAME_OVER
#define R96_WARIO_HELLO                           "wario_hello" //SOUND_WARIO_HELLO
#define R96_WARIO_PRESS_START_TO_PLAY             "wario_press_start_to_play" //SOUND_WARIO_PRESS_START_TO_PLAY
#define R96_WARIO_TWIRL_BOUNCE                    "wario_twirl_bounce" //SOUND_WARIO_TWIRL_BOUNCE
#define R96_WARIO_SNORING_3                       "wario_snoring_3" //SOUND_WARIO_SNORING3
#define R96_WARIO_SO_LONGA_BOWSER                 "wario_so_longa_bowser" //SOUND_WARIO_SO_LONGA_BOWSER
#define R96_WARIO_IMA_TIRED                       "wario_ima_tired" //SOUND_WARIO_IMA_TIRED
#define R96_WARIO_WAHA                            "wario_waha" //SOUND_WARIO_YAHOO_WAHA_YIPPEE
#define R96_WARIO_YIPPEE                          "wario_yippee"
#define R96_WARIO_SOUND_LETS_A_GO                 "wario_sound_lets_a_go" //SOUND_MENU_STAR_SOUND_LETS_A_GO
    
// sfx_wario_peach        
#define R96_WARIO_FALLING                         "wario_falling" //SOUND_WARIO_WAAAOOOW
#define R96_WARIO_HOOHOO                          "wario_hoohoo" //SOUND_WARIO_HOOHOO
#define R96_WARIO_PANTING                         "wario_panting" //SOUND_WARIO_PANTING
#define R96_WARIO_DYING                           "wario_dying" //SOUND_WARIO_DYING
#define R96_WARIO_ON_FIRE                         "wario_on_fire" //SOUND_WARIO_ON_FIRE
#define R96_WARIO_GRUNT_2                         "wario_grunt_2" //SOUND_WARIO_UH2_2
#define R96_WARIO_COUGHING_1                      "wario_coughing_1" //SOUND_WARIO_COUGHING1
#define R96_WARIO_ITS_A_ME_WARIO                  "wario_its_a_me_wario" //SOUND_MENU_COIN_ITS_A_ME_WARIO
#define R96_WARIO_PUNCH_YAH                       "wario_punch_yah" //SOUND_WARIO_PUNCH_YAH
#define R96_WARIO_PUNCH_HOO                       "wario_punch_hoo" //SOUND_WARIO_PUNCH_HOO
#define R96_WARIO_MAMA_MIA                        "wario_mama_mia" //SOUND_WARIO_MAMA_MIA
#define R96_WARIO_OKEY_DOKEY                      "wario_okey_dokey" //SOUND_WARIO_OKEY_DOKEY
#define R96_WARIO_DROWNING                        "wario_drowning" //SOUND_WARIO_DROWNING
#define R96_WARIO_THANK_YOU_PLAYING_MY_GAME       "wario_thank_you_playing_my_game" //SOUND_MENU_THANK_YOU_PLAYING_MY_GAME
#define R96_WARIO_PEACH_DEAR_WARIO                "wario_peach_dear_wario" //SOUND_PEACH_DEAR_WARIO
#define R96_WARIO_PEACH_WARIO                     "wario_peach_wario" //SOUND_PEACH_WARIO
#define R96_WARIO_PEACH_POWER_OF_THE_STARS        "wario_peach_power_of_the_stars" //SOUND_PEACH_POWER_OF_THE_STARS
#define R96_WARIO_PEACH_THANKS_TO_YOU             "wario_peach_thanks_to_you" //SOUND_PEACH_THANKS_TO_YOU
#define R96_WARIO_PEACH_THANK_YOU_WARIO           "wario_peach_thank_you_wario" //SOUND_PEACH_THANK_YOU_WARIO
#define R96_WARIO_PEACH_SOMETHING_SPECIAL         "wario_peach_something_special" //SOUND_PEACH_SOMETHING_SPECIAL
#define R96_WARIO_PEACH_BAKE_A_CAKE               "wario_peach_bake_a_cake" //SOUND_PEACH_BAKE_A_CAKE
#define R96_WARIO_PEACH_FOR_WARIO                 "wario_peach_for_wario" //SOUND_PEACH_FOR_WARIO
#define R96_WARIO_SOUND_PEACH_WARIO2              "wario_sound_peach_wario2" //SOUND_PEACH_WARIO2
#define R96_WARIO_PANTING_COLD                    "wario_panting_cold" //SOUND_WARIO_PANTING_COLD

#endif // R96_DEFINES_H
