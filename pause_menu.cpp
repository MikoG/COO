/* 
 * File:   pause_menu.cpp
 * Author: geth2k
 * 
 * Created on June 9, 2014, 6:58 PM
 */

#include "pause_menu.h"

pause_menu::pause_menu() {
    std::string strName = "pause_menu";
    this->set_name(strName);
    this->setup_ui();
}

pause_menu::pause_menu(const pause_menu& orig) :
control(orig) {
}

pause_menu::~pause_menu() {
}

void pause_menu::setup_ui() {
    control::t_color ColorBackground = control::t_color(0, 0, 0, 190);
    control::t_color ColorFrameBackground = control::t_color(50, 30, 50, 128);
    control::t_color ColorButtonBackground(70, 100, 160, 190);
    
    this->set_stretch_mode(5);
    this->set_colour(ColorBackground);
    this->paint();
    
    control* ctlButtons = new control();
    ctlButtons->set_width(250);
    ctlButtons->set_height(400);
    ctlButtons->set_hjustify_mode(control::eHJustifyTypes::center);
    ctlButtons->set_vjustify_mode(control::eVJustifyTypes::middle);
    ctlButtons->set_colour(ColorFrameBackground);
    this->add_child(ctlButtons);
    ctlButtons->set_parent(this);
    ctlButtons->paint();
    
    button* btnMainMenu = new button();
    btnMainMenu->set_parent(ctlButtons); 
    btnMainMenu->set_width(150);
    btnMainMenu->title->set_hjustify_mode(control::eHJustifyTypes::center);
    btnMainMenu->title->set_width(100);
    btnMainMenu->set_title("Main Menu");
    btnMainMenu->set_top(250);
    btnMainMenu->set_hjustify_mode(control::eHJustifyTypes::center);
    btnMainMenu->set_colour(ColorButtonBackground);
    btnMainMenu->set_mouse_up_event(button_mainmenu_mouse_up);
    
    ctlButtons->add_child(btnMainMenu);
    btnMainMenu->paint();
    
    button* btnPlay = new button();
    btnPlay->set_width(150);
    btnPlay->set_title("Play");
    btnPlay->title->set_hjustify_mode(control::eHJustifyTypes::center);
    btnPlay->title->set_width(50);
    btnPlay->set_top(300);
    btnPlay->set_hjustify_mode(control::eHJustifyTypes::center);
    btnPlay->set_colour(ColorButtonBackground);
    btnPlay->set_mouse_up_event(button_play_mouse_up);
    
    ctlButtons->add_child(btnPlay);
    btnPlay->set_parent(ctlButtons);
    
    this->_m_Data.unset_subdata_mask(ENABLED | VISIBLE);
    this->paint();
}

void button_play_mouse_up(object* sender, SDL_Event& evt) {
    button* senderButton = static_cast<button*> (sender);
    
    object::play_sound(100);
    
    SDL_Event PauseEvent;
    SDL_zero(PauseEvent);
    PauseEvent.user.type = sid::user_events::SID_PAUSE_GAME;
    SDL_PushEvent(&PauseEvent);   
}

void button_mainmenu_mouse_up(object* sender, SDL_Event& evt) {
    button* senderButton = static_cast<button*> (sender);
    
    object::play_sound(100);
    
    SDL_Event ExitGameEvent;
    SDL_zero(ExitGameEvent);
    ExitGameEvent.user.type = sid::user_events::SID_EXIT_GAME;
    SDL_PushEvent(&ExitGameEvent);   
}