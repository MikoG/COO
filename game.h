/* 
 * File:   game.h
 * Author: geth2k
 *
 * Created on 29 November 2013, 19:37
 */

#ifndef GAME_H
#define	GAME_H

#include "../SID/SID_perlin.h"
#include "../SID/SID_api.h"
#include "debug_pane.h"
#include "mission_planner.h"
#include "game_menu.h"
#include "clickmode_panel.h"
#include "loading_screen.h"
#include "main_menu.h"
#include "pause_menu.h"
#include "biome_land_mass.h"
#include "biome_default.h"
#include "biome_hills.h"

class game : public sid::api {
public:
    game();
    game(const game& orig);
    virtual ~game();
    
    virtual void build_main_menu();
    virtual void init_engine();
    virtual void run_gameloop();
    virtual void add_ingame_menus();
    virtual void add_debug_form();
    virtual void load_gametextures();
    virtual void load_fonts();
    virtual void load_music();
    virtual void pause_game();
    virtual void unpause_game();
    
    void set_debug_info();
    
private:
    
};



#endif	/* GAME_H */

