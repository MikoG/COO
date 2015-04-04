/* 
 * File:   main_menu.cpp
 * Author: geth2k
 * 
 * Created on June 8, 2014, 9:37 PM
 */

#include "main_menu.h"

main_menu::main_menu() {
    std::string strName = "main_menu";
    this->set_name(strName);
    this->setup_ui();
}

main_menu::main_menu(const main_menu& orig) :
control(orig) {
}

main_menu::~main_menu() {
    std::cout << "main_menu Destructor" << std::endl;
    object::_s_Audio.fade_out(2000);
}

void main_menu::setup_ui() {
    
    control::t_color ColorFrameBG(50, 30, 50, 128);
    control::t_color ColorButtonBG(70, 100, 160, 190);
    

    object::_s_Audio.fade_in_song(100, 2000);
    this->set_stretch_mode(5);
    this->set_texture_ID(object::_s_Textures.get_tex_id_by_ref(2));

    std::vector<int> viWidths;
    viWidths.push_back(180);
    layout* lyt = new layout(22, viWidths, 15);

    control* ctlFrame = new control();
    ctlFrame->set_parent(this);
    std::string strButtonsName = "main_menu_buttons";
    ctlFrame->set_name(strButtonsName);
    ctlFrame->set_width(220);
    ctlFrame->set_height(140);
    ctlFrame->set_hjustify_mode(control::eHJustifyTypes::center);
    ctlFrame->set_vjustify_mode(control::eVJustifyTypes::middle);
    ctlFrame->set_colour(ColorFrameBG);
    ctlFrame->paint();
    this->add_child(ctlFrame);

    // Make the "Play" button.

    button* btnStart = new button();
    btnStart->set_parent(ctlFrame);
    std::string strPlayButtonName = "play_button";
    btnStart->set_name(strPlayButtonName);
    btnStart->set_width(200);

    btnStart->title->set_width(95);
    btnStart->title->set_hjustify_mode(
            control::eHJustifyTypes::center);

    btnStart->set_title("Play Game");
    btnStart->set_mouse_up_event(button_start_mouse_up);
    btnStart->set_mouse_in_event(button_mouse_in);
    btnStart->set_mouse_out_event(button_mouse_out);

    btnStart->set_colour(ColorButtonBG);
    btnStart->paint();
    ctlFrame->add_child(btnStart);

    // Make the "Settings" button.

    button* btnSetting = new button();
    btnSetting->set_parent(ctlFrame);
    std::string strSettingsButtonName = "settings_button";
    btnSetting->set_name(strSettingsButtonName);
    btnSetting->set_width(200);

    btnSetting->title->set_width(80);
    btnSetting->title->set_hjustify_mode(
            control::eHJustifyTypes::center);

    btnSetting->set_title("Settings");
    btnSetting->set_mouse_in_event(button_mouse_in);
    btnSetting->set_mouse_out_event(button_mouse_out);


    btnSetting->set_colour(ColorButtonBG);
    
    btnSetting->paint();
    ctlFrame->add_child(btnSetting);

    // Make the "Quit" button.

    button* btnQuit = new button();
    btnQuit->set_parent(ctlFrame);
    std::string strQuitButtonName = "quit_button";
    btnQuit->set_name(strQuitButtonName);
    btnQuit->set_width(200);

    btnQuit->title->set_width(50);
    btnQuit->title->set_hjustify_mode(
            control::eHJustifyTypes::center);


    
    btnQuit->set_title("Quit");
    btnQuit->set_mouse_up_event(button_quit_mouse_up);
    btnQuit->set_mouse_in_event(button_mouse_in);
    btnQuit->set_mouse_out_event(button_mouse_out);

    btnQuit->set_colour(ColorButtonBG);

    btnQuit->paint();
    ctlFrame->add_child(btnQuit);

    // Apply the layout to loaded child objects.
    ctlFrame->set_layout(lyt);

    // Cascade a paint command.
    this->paint();
}

void button_start_mouse_up(object* sender, SDL_Event& evt) {
    button* senderButton = static_cast<button*> (sender);
    object* senderParent;
    senderParent = sender->get_parent()->get_parent();

    object::play_sound(100);

    SDL_Event CloseControlEvent;
    SDL_zero(CloseControlEvent);
    CloseControlEvent.user.type = sid::user_events::SID_CLOSE_FORM;
    CloseControlEvent.user.data1 = static_cast<void*> (senderParent);
    SDL_PushEvent(&CloseControlEvent);

    SDL_Event StartGameEvent;
    SDL_zero(StartGameEvent);
    StartGameEvent.user.type = sid::user_events::SID_START_GAME;
    SDL_PushEvent(&StartGameEvent);
}

void button_mouse_in(object* sender, SDL_Event& evt) {
    button* senderButton = static_cast<button*> (sender);
    object* senderParent;
    senderParent = sender->get_parent()->get_parent();

    object::play_sound(100);
    
    control::t_color ColorButtonBG(0, 128, 255, 190);
    senderButton->set_colour(ColorButtonBG);

    senderButton->paint();
}

void button_mouse_out(object* sender, SDL_Event& evt) {
    button* senderButton = static_cast<button*> (sender);
    object* senderParent;
    senderParent = sender->get_parent()->get_parent();

    control::t_color ColorButtonBG(70, 100, 160, 190);
    senderButton->set_colour(ColorButtonBG);
    senderButton->paint();
}

void button_quit_mouse_up(object* sender, SDL_Event& evt) {
    button* senderButton = static_cast<button*> (sender);

    SDL_Event QuitGameEvent;
    SDL_zero(QuitGameEvent);
    QuitGameEvent.type = SDL_QUIT;
    SDL_PushEvent(&QuitGameEvent);

}