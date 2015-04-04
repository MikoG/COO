/* 
 * File:   game_menu.cpp
 * Author: geth2k
 * 
 * Created on 06 December 2013, 00:56
 */

#include "game_menu.h"

game_menu::game_menu() {
    std::string strMenuName = "Menu";
    this->set_name(strMenuName);
    this->setup_ui();
    this->paint();
}

game_menu::game_menu(const game_menu& orig) :
menu_bar(orig) {
}

game_menu::~game_menu() {
}

void game_menu::setup_ui() {
    uint uiTexID1 = object::_s_Textures.get_tex_id_by_ref(101);
    this->set_texture_ID(uiTexID1);    
    this->set_height(26);
    this->set_margin(1);

    button* btn1 = new button();
    btn1->set_parent(this);
    btn1->set_title("File");
    btn1->set_width(60);
    this->add_child(btn1);

    button* btn2 = new button();
    btn2->set_parent(this);
    btn2->set_title("Edit");
    btn2->set_width(60);
    this->add_child(btn2);

    button* btn3 = new button();
    btn3->set_parent(this);
    btn3->set_title("View");
    btn3->set_width(60);
    this->add_child(btn3);

    button* btn4 = new button();
    btn4->set_parent(this);
    btn4->set_title("Help");
    btn4->set_width(60);
    this->add_child(btn4);
}

void game_menu::set_event_functions() {

}