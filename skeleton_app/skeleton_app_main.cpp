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

#include "skeleton_app.h"
#include "skeleton_app_main.h"

#include "gui/mainbar/app_tile/app_tile.h"
#include "gui/mainbar/main_tile/main_tile.h"
#include "gui/mainbar/mainbar.h"
#include "gui/statusbar.h"

lv_obj_t *skeleton_app_main_tile = NULL;
lv_style_t skeleton_app_main_style;

// lv_task_t * _skeleton_app_task;

LV_IMG_DECLARE(exit_32px);
LV_FONT_DECLARE(Ubuntu_72px);

static void exit_skeleton_app_main_event_cb( lv_obj_t * obj, lv_event_t event );
//void skeleton_app_task( lv_task_t * task );

void skeleton_app_main_setup( uint32_t tile_num ) {

    skeleton_app_main_tile = mainbar_get_tile_obj( tile_num );
    lv_style_copy( &skeleton_app_main_style, mainbar_get_style() );

    lv_obj_t * exit_btn = lv_imgbtn_create( skeleton_app_main_tile, NULL);
    lv_imgbtn_set_src(exit_btn, LV_BTN_STATE_RELEASED, &exit_32px);
    lv_imgbtn_set_src(exit_btn, LV_BTN_STATE_PRESSED, &exit_32px);
    lv_imgbtn_set_src(exit_btn, LV_BTN_STATE_CHECKED_RELEASED, &exit_32px);
    lv_imgbtn_set_src(exit_btn, LV_BTN_STATE_CHECKED_PRESSED, &exit_32px);
    lv_obj_add_style(exit_btn, LV_IMGBTN_PART_MAIN, &skeleton_app_main_style );
    lv_obj_align(exit_btn, skeleton_app_main_tile, LV_ALIGN_IN_BOTTOM_LEFT, 10, -10 );
    lv_obj_set_event_cb( exit_btn, exit_skeleton_app_main_event_cb );

    // optionally create a task that runs every second (to poll something etc)  
    // _skeleton_app_task = lv_task_create( skeleton_app_task, 1000, LV_TASK_PRIO_MID, NULL );
}

static void exit_skeleton_app_main_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):       mainbar_jump_to_maintile( LV_ANIM_OFF );
                                        break;
    }
}

//void skeleton_app_task( lv_task_t * task ) {
//
//    (If you created a task to run each second then the code should go here)
//          
//}
