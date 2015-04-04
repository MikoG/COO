/* 
 * File:   clickmode_panel.cpp
 * Author: geth2k
 * 
 * Created on 18 March 2014, 22:37
 */

#include "clickmode_panel.h"

using namespace sid;

clickmode_panel::clickmode_panel() :
m_iMouseMode(0) {
    std::string strName = "clickmode_panel";
    this->set_name(strName);
    this->setup_ui();
}

clickmode_panel::clickmode_panel(const clickmode_panel& orig) :
control(orig),
m_iMouseMode(orig.m_iMouseMode) {
}

clickmode_panel::~clickmode_panel() {
    delete this->m_rbgMouseModes;
}

void clickmode_panel::set_mouse_mode(int clickMode) {
    this->m_iMouseMode = clickMode;
}

int clickmode_panel::get_mouse_mode() const {
    return m_iMouseMode;
}

void clickmode_panel::setup_ui() {
    uint uiTexID1 = object::_s_Textures.get_tex_id_by_ref(102);
    this->set_texture_ID(uiTexID1);

    this->set_width(200.0);
    this->set_height(200.0);
    this->set_hjustify_mode(control::eHJustifyTypes::right);
    this->set_vjustify_mode(control::eVJustifyTypes::bottom);

    this->m_rbgMouseModes = new radio_button::rb_group;

    this->m_ctlFightMode = new radio_button();
    this->m_rbgMouseModes->add(this->m_ctlFightMode);
    uint uiTexID2 = object::_s_Textures.get_tex_id_by_ref(103);
    this->m_ctlFightMode->set_texture_ID(uiTexID2);
    this->m_ctlFightMode->StatusImages.set_image_ID(
            button::state_images::eStates::ON, 104);
    this->m_ctlFightMode->StatusImages.set_image_ID(
            button::state_images::eStates::OFF, 103);
    this->m_ctlFightMode->set_width(49);
    this->m_ctlFightMode->set_height(49);
    this->m_ctlFightMode->set_top(15);
    this->m_ctlFightMode->set_left(133);
    this->m_ctlFightMode->set_title("Fight");
    std::string strFightBtn = "fight_button";
    this->m_ctlFightMode->set_name(strFightBtn);
    this->m_ctlFightMode->set_parent(this);
    this->m_ctlFightMode->set_mouse_up_event(toggle_fight_mouse_up);
    this->m_ctlFightMode->set_group(this->m_rbgMouseModes);
    this->add_child(this->m_ctlFightMode);

    this->m_ctlBuildMode = new radio_button();
    this->m_rbgMouseModes->add(this->m_ctlBuildMode);
    uint uiTexID3 = object::_s_Textures.get_tex_id_by_ref(105);
    this->m_ctlBuildMode->set_texture_ID(uiTexID3);
    this->m_ctlBuildMode->StatusImages.set_image_ID(
            button::state_images::eStates::ON, 106);
    this->m_ctlBuildMode->StatusImages.set_image_ID(
            button::state_images::eStates::OFF, 105);
    this->m_ctlBuildMode->set_width(49);
    this->m_ctlBuildMode->set_height(49);
    this->m_ctlBuildMode->set_top(38);
    this->m_ctlBuildMode->set_left(76);
    this->m_ctlBuildMode->set_title("Build");
    std::string strBuildBtn = "build_button";
    this->m_ctlBuildMode->set_name(strBuildBtn);
    this->m_ctlBuildMode->set_parent(this);
    this->m_ctlBuildMode->set_mouse_up_event(toggle_build_mouse_up);
    this->add_child(this->m_ctlBuildMode);

    this->m_ctlTerrainMode = new radio_button();
    this->m_rbgMouseModes->add(this->m_ctlTerrainMode);
    uint uiTexID4 = object::_s_Textures.get_tex_id_by_ref(107);
    this->m_ctlTerrainMode->set_texture_ID(uiTexID4);
    this->m_ctlTerrainMode->StatusImages.set_image_ID(
            button::state_images::eStates::ON, 108);
    this->m_ctlTerrainMode->StatusImages.set_image_ID(
            button::state_images::eStates::OFF, 107);
    this->m_ctlTerrainMode->set_width(49);
    this->m_ctlTerrainMode->set_height(49);
    this->m_ctlTerrainMode->set_top(86);
    this->m_ctlTerrainMode->set_left(33);
    this->m_ctlTerrainMode->title->set_width(80);
    this->m_ctlTerrainMode->set_title("Terrain");
    std::string strTerrainBtn = "terrain_button";
    this->m_ctlTerrainMode->set_name(strTerrainBtn);
    this->m_ctlTerrainMode->set_parent(this);
    this->m_ctlTerrainMode->set_mouse_up_event(toggle_terrain_mouse_up);
    this->add_child(this->m_ctlTerrainMode);

    this->m_ctlQueryMode = new radio_button();
    this->m_rbgMouseModes->add(this->m_ctlQueryMode);
    uint uiTexID5 = object::_s_Textures.get_tex_id_by_ref(109);
    this->m_ctlQueryMode->set_texture_ID(uiTexID5);
    this->m_ctlQueryMode->StatusImages.set_image_ID(
            button::state_images::eStates::ON, 110);
    this->m_ctlQueryMode->StatusImages.set_image_ID(
            button::state_images::eStates::OFF, 109);
    this->m_ctlQueryMode->set_width(49);
    this->m_ctlQueryMode->set_height(49);
    this->m_ctlQueryMode->set_top(142);
    this->m_ctlQueryMode->set_left(6);
    this->m_ctlQueryMode->set_title("Query");
    std::string strQueryBtn = "query_button";
    this->m_ctlQueryMode->set_name(strQueryBtn);
    this->m_ctlQueryMode->set_parent(this);
    this->m_ctlQueryMode->set_mouse_up_event(toggle_terrain_mouse_up);
    this->add_child(this->m_ctlQueryMode);
    
    this->paint();
}

void toggle_fight_mouse_up(object* sender, SDL_Event& evt) {
    radio_button* senderToggle = static_cast<radio_button*> (sender);
    clickmode_panel* senderParent;
    senderParent = static_cast<clickmode_panel*> (sender->get_parent());
    if (senderToggle->get_state() == button::state_images::ON) {
        senderParent->set_mouse_mode(1);
    } else if (senderToggle->get_state() == button::state_images::OFF) {
        senderParent->set_mouse_mode(0);
    }

    object::play_sound(100);
}

void toggle_build_mouse_up(object* sender, SDL_Event& evt) {
    radio_button* senderToggle = static_cast<radio_button*> (sender);
    clickmode_panel* senderParent;
    senderParent = static_cast<clickmode_panel*> (sender->get_parent());
    if (senderToggle->get_state() == button::state_images::ON) {
        senderParent->set_mouse_mode(2);
    } else if (senderToggle->get_state() == button::state_images::OFF) {
        senderParent->set_mouse_mode(0);
    }

    object::play_sound(100);
}

void toggle_terrain_mouse_up(object* sender, SDL_Event& evt) {
    radio_button* senderToggle = static_cast<radio_button*> (sender);
    clickmode_panel* senderParent;
    senderParent = static_cast<clickmode_panel*> (sender->get_parent());
    if (senderToggle->get_state() == button::state_images::ON) {
        senderParent->set_mouse_mode(3);
    } else if (senderToggle->get_state() == button::state_images::OFF) {
        senderParent->set_mouse_mode(0);
    }


    object::play_sound(100);
}

void toggle_query_mouse_up(object* sender, SDL_Event& evt) {
    radio_button* senderToggle = static_cast<radio_button*> (sender);
    clickmode_panel* senderParent;
    senderParent = static_cast<clickmode_panel*> (sender->get_parent());
    if (senderToggle->get_state() == button::state_images::ON) {
        senderParent->set_mouse_mode(4);
    } else if (senderToggle->get_state() == button::state_images::OFF) {
        senderParent->set_mouse_mode(0);
    }


    object::play_sound(100);
}