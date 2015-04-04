/* 
 * File:   mission_planner.cpp
 * Author: geth2k
 * 
 * Created on 06 December 2013, 02:06
 */

#include "mission_planner.h"

mission_planner::mission_planner() {
    std::string strObjBrwsrName = "Mission_Planner";
    this->set_name(strObjBrwsrName);
    this->setup_ui();
}

mission_planner::mission_planner(const mission_planner& orig) : 
control(orig) {
}

mission_planner::~mission_planner() {
}

void mission_planner::setup_ui() {
    this->set_stretch_mode(4);
    this->set_height(600.0);
    this->set_width(150.0);
    this->set_top(26.0);
    this->set_left(0.0);
    this->set_margin(10);
    uint uiTexID1 = object::_s_Textures.get_tex_id_by_ref(100);
    this->set_texture_ID(uiTexID1);

    this->paint();
}