/* 
 * File:   main_menu.h
 * Author: geth2k
 *
 * Created on June 8, 2014, 9:37 PM
 */

#ifndef MAIN_MENU_H
#define	MAIN_MENU_H

#include "../SID/SID_control.h"
#include "../SID/SID_button.h"
#include "../SID/SID_user_events.h"

using namespace sid;

class main_menu : public control {
public:
    main_menu();
    main_menu(const main_menu& orig);
    virtual ~main_menu();
    
    virtual void setup_ui();
private:

};

void button_mouse_in(object* sender, SDL_Event& evt);
void button_mouse_out(object* sender, SDL_Event& evt);
void button_start_mouse_up(object* sender, SDL_Event& evt);
void button_quit_mouse_up(object* sender, SDL_Event& evt);

#endif	/* MAIN_MENU_H */

