/* 
 * File:   pause_menu.h
 * Author: geth2k
 *
 * Created on June 9, 2014, 6:58 PM
 */

#ifndef PAUSE_MENU_H
#define	PAUSE_MENU_H

#include "../SID/SID_control.h"
#include "../SID/SID_button.h"
#include "../SID/SID_user_events.h"

using namespace sid;

class pause_menu : public control {
public:
    pause_menu();
    pause_menu(const pause_menu& orig);
    virtual ~pause_menu();
    
    virtual void setup_ui();
private:

};

void button_play_mouse_up(object* sender, SDL_Event& evt);
void button_mainmenu_mouse_up(object* sender, SDL_Event& evt);

#endif	/* PAUSE_MENU_H */

