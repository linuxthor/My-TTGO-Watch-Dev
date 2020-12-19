/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "config.h"
#include <TTGO.h>

#include "soundboard_app.h"
#include "soundboard_app_main.h"

#include "gui/mainbar/app_tile/app_tile.h"
#include "gui/mainbar/main_tile/main_tile.h"
#include "gui/mainbar/mainbar.h"
#include "gui/statusbar.h"

#include "hardware/sound.h"

lv_obj_t *soundboard_app_main_tile = NULL;
lv_style_t soundboard_app_main_style;

lv_task_t * _soundboard_app_task;

LV_IMG_DECLARE(exit_32px);
LV_IMG_DECLARE(button_64px);
LV_FONT_DECLARE(Ubuntu_72px);

// buttons
static void enter_soundboard_app_zero_event_cb( lv_obj_t * obj, lv_event_t event );
static void enter_soundboard_app_one_event_cb( lv_obj_t * obj, lv_event_t event );
static void enter_soundboard_app_two_event_cb( lv_obj_t * obj, lv_event_t event );
static void enter_soundboard_app_three_event_cb( lv_obj_t * obj, lv_event_t event );

static void exit_soundboard_app_main_event_cb( lv_obj_t * obj, lv_event_t event );

void soundboard_app_main_setup( uint32_t tile_num ) {

    soundboard_app_main_tile = mainbar_get_tile_obj( tile_num );
    lv_style_copy( &soundboard_app_main_style, mainbar_get_style() );

    // 0
    lv_obj_t * zero_btn = lv_imgbtn_create( soundboard_app_main_tile, NULL);
    lv_imgbtn_set_src(zero_btn, LV_BTN_STATE_RELEASED, &button_64px);
    lv_imgbtn_set_src(zero_btn, LV_BTN_STATE_PRESSED, &button_64px);
    lv_imgbtn_set_src(zero_btn, LV_BTN_STATE_CHECKED_RELEASED, &button_64px);
    lv_imgbtn_set_src(zero_btn, LV_BTN_STATE_CHECKED_PRESSED, &button_64px);
    lv_obj_add_style(zero_btn, LV_IMGBTN_PART_MAIN, &soundboard_app_main_style );
    lv_obj_align(zero_btn, soundboard_app_main_tile, LV_ALIGN_IN_TOP_LEFT, 0, 0 );
    lv_obj_set_event_cb( zero_btn, enter_soundboard_app_zero_event_cb );
 
    // 1
    lv_obj_t * one_btn = lv_imgbtn_create( soundboard_app_main_tile, NULL);
    lv_imgbtn_set_src(one_btn, LV_BTN_STATE_RELEASED, &button_64px);
    lv_imgbtn_set_src(one_btn, LV_BTN_STATE_PRESSED, &button_64px);
    lv_imgbtn_set_src(one_btn, LV_BTN_STATE_CHECKED_RELEASED, &button_64px);
    lv_imgbtn_set_src(one_btn, LV_BTN_STATE_CHECKED_PRESSED, &button_64px);
    lv_obj_add_style(one_btn, LV_IMGBTN_PART_MAIN, &soundboard_app_main_style );
    lv_obj_align(one_btn, soundboard_app_main_tile, LV_ALIGN_IN_TOP_RIGHT, 0, 0 );
    lv_obj_set_event_cb( one_btn, enter_soundboard_app_one_event_cb );

    // 2
    lv_obj_t * two_btn = lv_imgbtn_create( soundboard_app_main_tile, NULL);
    lv_imgbtn_set_src(two_btn, LV_BTN_STATE_RELEASED, &button_64px);
    lv_imgbtn_set_src(two_btn, LV_BTN_STATE_PRESSED, &button_64px);
    lv_imgbtn_set_src(two_btn, LV_BTN_STATE_CHECKED_RELEASED, &button_64px);
    lv_imgbtn_set_src(two_btn, LV_BTN_STATE_CHECKED_PRESSED, &button_64px);
    lv_obj_add_style(two_btn, LV_IMGBTN_PART_MAIN, &soundboard_app_main_style );
    lv_obj_align(two_btn, soundboard_app_main_tile, LV_ALIGN_IN_LEFT_MID, 0, 0 );
    lv_obj_set_event_cb( two_btn, enter_soundboard_app_two_event_cb );

    // 3 
    lv_obj_t * three_btn = lv_imgbtn_create( soundboard_app_main_tile, NULL);
    lv_imgbtn_set_src(three_btn, LV_BTN_STATE_RELEASED, &button_64px);
    lv_imgbtn_set_src(three_btn, LV_BTN_STATE_PRESSED, &button_64px);
    lv_imgbtn_set_src(three_btn, LV_BTN_STATE_CHECKED_RELEASED, &button_64px);
    lv_imgbtn_set_src(three_btn, LV_BTN_STATE_CHECKED_PRESSED, &button_64px);
    lv_obj_add_style(three_btn, LV_IMGBTN_PART_MAIN, &soundboard_app_main_style );
    lv_obj_align(three_btn, soundboard_app_main_tile, LV_ALIGN_IN_RIGHT_MID, 0, 0 );
    lv_obj_set_event_cb( three_btn, enter_soundboard_app_three_event_cb );

    lv_obj_t * exit_btn = lv_imgbtn_create( soundboard_app_main_tile, NULL);
    lv_imgbtn_set_src(exit_btn, LV_BTN_STATE_RELEASED, &exit_32px);
    lv_imgbtn_set_src(exit_btn, LV_BTN_STATE_PRESSED, &exit_32px);
    lv_imgbtn_set_src(exit_btn, LV_BTN_STATE_CHECKED_RELEASED, &exit_32px);
    lv_imgbtn_set_src(exit_btn, LV_BTN_STATE_CHECKED_PRESSED, &exit_32px);
    lv_obj_add_style(exit_btn, LV_IMGBTN_PART_MAIN, &soundboard_app_main_style );
    lv_obj_align(exit_btn, soundboard_app_main_tile, LV_ALIGN_IN_BOTTOM_RIGHT, -10, -10 );
    lv_obj_set_event_cb( exit_btn, exit_soundboard_app_main_event_cb );
}

static void enter_soundboard_app_zero_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):      sound_play_spiffs_mp3( "/sound0.mp3" );
                                       break;
    }
}

static void enter_soundboard_app_one_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):      sound_play_spiffs_mp3( "/sound1.mp3" );
                                       break;
    }
}

static void enter_soundboard_app_two_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):      sound_play_spiffs_mp3( "/sound2.mp3" ); 
                                       break;
    }
}

static void enter_soundboard_app_three_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):      sound_play_spiffs_mp3( "/sound3.mp3" );
                                       break;
    }
}

static void exit_soundboard_app_main_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):       mainbar_jump_to_maintile( LV_ANIM_OFF );
                                        break;
    }
}


