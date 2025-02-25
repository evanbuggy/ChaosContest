#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "config/config_cutscenes.h"

#include "game/area.h"
#include "game/level_update.h"
#include "menu/file_select.h"
#include "menu/star_select.h"

#include "levels/scripts.h"

#include "actors/group0.h"
#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/menu/header.h"

const LevelScript level_main_menu_entry_file_select[] = {
#ifndef SKIP_FILE_SELECT
    INIT_LEVEL(),
    LOAD_GODDARD(),
    LOAD_LEVEL_DATA(menu),
    LOAD_BEHAVIOR_DATA(),
    LOAD_YAY0(          /*seg*/ SEGMENT_GROUP0_YAY0, _group0_yay0SegmentRomStart, _group0_yay0SegmentRomEnd),
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_GROUP0_GEO,   _group0_geoSegmentRomStart,  _group0_geoSegmentRomEnd, _group0_geoSegmentBssStart, _group0_geoSegmentBssEnd),
    ALLOC_LEVEL_POOL(),
    LOAD_MODEL_FROM_GEO(MODEL_SHADOW_TITLE_SCREEN,                   shadow_mario_title_geo),
    LOAD_MODEL_FROM_GEO(MODEL_TITLE_SCREEN_BG,                       title_bg_geo),
    LOAD_MODEL_FROM_GEO(MODEL_TITLE_SCREEN_TITLE,                    title_logo_geo),
    LOAD_MODEL_FROM_GEO(MODEL_STAR_SELECT_BG,                        starselectbg_geo),


    AREA(/*index*/ 1, geo_menu_file_select_strings_and_menu_cursor),
        //OBJECT(/*model*/ MODEL_NONE,                         /*pos*/ 0, 0, -19000, /*angle*/ 0, 0, 0, /*behParam*/ BP(0x04, 0x00, 0x00, 0x00), /*beh*/ bhvMenuButtonManager),
        // PHIL564: KING OF THE JANK
        OBJECT(/*model*/ MODEL_SHADOW_TITLE_SCREEN, /*pos*/ 1000, 5, 730, /*angle*/ 0, 0, 0, /*behParam*/ 0, /*beh*/ bhvMovingShadow),
        OBJECT(/*model*/ MODEL_TITLE_SCREEN_TITLE, /*pos*/ 1600, 5, 730, /*angle*/ 0, 0, 0, /*behParam*/ 0, /*beh*/ bhvMovingTitle),
        OBJECT(/*model*/ MODEL_TITLE_SCREEN_BG, /*pos*/ 0, -20, 50, /*angle*/ 0, 0, 0, /*behParam*/ 0, /*beh*/ bhvTitleStaticObject),
        TERRAIN(/*terrainData*/ main_menu_seg7_collision),
    END_AREA(),

    FREE_LEVEL_POOL(),
    SET_MENU_MUSIC(/*seq*/ SEQ_MENU_TITLE_SCREEN),
    SLEEP(/*frames*/ 50),
    LOAD_AREA(/*area*/ 1),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    CALL(     /*arg*/ 0, /*func*/ lvl_init_menu_values_and_cursor_pos),
    CALL_LOOP(/*arg*/ 0, /*func*/ lvl_update_obj_and_load_file_selected),
    GET_OR_SET(/*op*/ OP_SET, /*var*/ VAR_CURR_SAVE_FILE_NUM),
    STOP_MUSIC(/*fadeOutTime*/ 0x00BE),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
#endif // SKIP_FILE_SELECT
    SET_REG(LEVEL_CASTLE_COURTYARD),
    EXIT_AND_EXECUTE(/*seg*/ SEGMENT_GLOBAL_LEVEL_SCRIPT, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, level_main_scripts_entry),
};

const LevelScript level_main_menu_entry_act_select_exit[] = {
    EXIT(),
};

const LevelScript level_main_menu_entry_act_select[] = {
    CALL(/*arg*/ 0, /*func*/ lvl_set_current_level),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ FALSE, (level_main_menu_entry_act_select_exit)),
    INIT_LEVEL(),
    LOAD_GODDARD(),
    LOAD_LEVEL_DATA(menu),
    ALLOC_LEVEL_POOL(),

    AREA(/*index*/ 2, geo_menu_act_selector_strings),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ 0, -100, 0, /*angle*/ 0, 0, 0, /*behParam*/ BP(0x04, 0x00, 0x00, 0x00), /*beh*/ bhvActSelector),
        OBJECT(MODEL_STAR_SELECT_BG,  0, 0, -600,       0, 0, 0, 0x00000000, bhvStaticObject),
    TERRAIN(/*terrainData*/ main_menu_seg7_collision),
END_AREA(),

    FREE_LEVEL_POOL(),
    LOAD_AREA(/*area*/ 2),
#ifdef NO_SEGMENTED_MEMORY
        // sVisibleStars is set to 0 during FIXED_LOAD above on N64, but not when NO_SEGMENTED_MEMORY is used.
        // lvl_init_act_selector_values_and_stars must be called here otherwise the previous
        // value is retained and causes incorrect drawing during the 16 transition frames.
        CALL(/*arg*/ 0, /*func*/ lvl_init_act_selector_values_and_stars),
#endif
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    SET_MENU_MUSIC(/*seq*/ 0x000D),
#ifndef NO_SEGMENTED_MEMORY
    CALL(     /*arg*/ 0, /*func*/ lvl_init_act_selector_values_and_stars),
#endif
    CALL_LOOP(/*arg*/ 0, /*func*/ lvl_update_obj_and_load_act_button_actions),
    GET_OR_SET(/*op*/ OP_SET, /*var*/ VAR_CURR_ACT_NUM),
    STOP_MUSIC(/*fadeOutTime*/ 0x00BE),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),

    EXIT(),
};
