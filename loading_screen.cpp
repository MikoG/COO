/* 
 * File:   loading_screen.cpp
 * Author: geth2k
 * 
 * Created on June 7, 2014, 11:04 PM
 */

#include "loading_screen.h"

loading_screen::loading_screen() {
    std::string strTitle = "loading_screen";
    this->set_name(strTitle);
    this->setup_ui();
}

loading_screen::loading_screen(const loading_screen& orig) :
control(orig) {
}

loading_screen::~loading_screen() {
}

void loading_screen::setup_ui() {
    uint uiTexID1 = object::_s_Textures.get_tex_id_by_ref(1);
    this->set_texture_ID(uiTexID1);
    this->set_width(sid::get_screen_width());
    this->set_height(sid::get_screen_height());
    this->set_hjustify_mode(control::eHJustifyTypes::left);
    this->set_vjustify_mode(control::eVJustifyTypes::top);

    this->paint();
}

