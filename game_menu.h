/* 
 * File:   game_menu.h
 * Author: geth2k
 *
 * Created on 06 December 2013, 00:56
 */

#ifndef GAME_MENU_H
#define	GAME_MENU_H

#include "../3DOAPI_0_1/SID_menu_bar.h"

using namespace sid;

class game_menu : public menu_bar {
public:
    game_menu();
    game_menu(const game_menu& orig);
    virtual ~game_menu();
    
protected:
    void setup_ui();
    virtual void set_event_functions();
private:

};

#endif	/* GAME_MENU_H */

