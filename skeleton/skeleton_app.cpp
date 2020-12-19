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
#include "skeleton_app_setup.h"

#include "gui/mainbar/mainbar.h"
#include "gui/statusbar.h"
#include "gui/app.h"
#include "gui/widget.h"

uint32_t skeleton_app_main_tile_num;
uint32_t skeleton_app_setup_tile_num;

// app icon
icon_t *skeleton_app = NULL;

// declare you images or fonts you need
LV_IMG_DECLARE(skeleton_app_64px);
LV_IMG_DECLARE(info_1_16px);

// declare callback functions for the app and widget icon to enter the app
static void enter_skeleton_app_event_cb( lv_obj_t * obj, lv_event_t event );

/*
 * setup routine for skeleton app
 */
void skeleton_app_setup( void ) {
    skeleton_app_main_tile_num = mainbar_add_app_tile( 1, 1, "skeleton app" );
    skeleton_app = app_register( "skeleton", &skeleton_app_64px, enter_skeleton_app_event_cb );
    skeleton_app_main_setup( skeleton_app_main_tile_num );
}

/*
 *
 */
uint32_t skeleton_app_get_app_main_tile_num( void ) {
    return( skeleton_app_main_tile_num );
}

/*
 *
 */
static void enter_skeleton_app_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):       statusbar_hide( true );
                                        mainbar_jump_to_tilenumber( skeleton_app_main_tile_num, LV_ANIM_OFF );
                                        break;
    }    
}

