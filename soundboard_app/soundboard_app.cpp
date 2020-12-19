#include "config.h"
#include <TTGO.h>

#include "soundboard_app.h"
#include "soundboard_app_main.h"

#include "gui/mainbar/mainbar.h"
#include "gui/statusbar.h"
#include "gui/app.h"

uint32_t soundboard_app_main_tile_num;
icon_t *soundboard_app = NULL;

LV_IMG_DECLARE(soundboard_app_64px);
LV_IMG_DECLARE(info_1_16px);

static void enter_soundboard_app_event_cb( lv_obj_t * obj, lv_event_t event );

/*
 * setup routine for soundboard app
 */
void soundboard_app_setup( void ) {
    soundboard_app_main_tile_num = mainbar_add_app_tile( 1, 1, "soundboard" );
    soundboard_app = app_register( "sound\nboard", &soundboard_app_64px, enter_soundboard_app_event_cb );
    soundboard_app_main_setup( soundboard_app_main_tile_num );
}

/*
 *
 */
uint32_t soundboard_app_get_app_main_tile_num( void ) {
    return( soundboard_app_main_tile_num );
}

/*
 *
 */
static void enter_soundboard_app_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):       statusbar_hide( true );
                                        app_hide_indicator( soundboard_app );
                                        mainbar_jump_to_tilenumber( soundboard_app_main_tile_num, LV_ANIM_OFF );
                                        break;
    }    
}

