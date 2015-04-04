/* 
 * File:   debug_pane.cpp
 * Author: geth2k
 * 
 * Created on 05 December 2013, 23:57
 */

#include <list>

#include "debug_pane.h"

debug_pane::debug_pane() {
    std::string strObjBrwsrName = "Debug";
    this->set_name(strObjBrwsrName);
    this->setup_ui();
}

debug_pane::debug_pane(const debug_pane& orig) :
control(orig) {
}

debug_pane::~debug_pane() {

}

void debug_pane::setup_ui() {
    control::t_color ColorBackground = control::t_color(0, 0, 0, 170);
    control::t_color ColorLabelBackground = control::t_color(0, 0, 0, 0);
    control::t_color ColorLabelForeground = control::t_color(255, 255, 255, 255);

#ifdef DEBUG
    this->set_visible(true);
    this->set_enabled(true);
#else
    this->set_visible(false);
    this->set_enabled(false);
#endif
    this->set_height(130.0);
    this->set_width(200.0);
    this->set_top(26.0);
    this->set_left(0.0);
    this->set_hjustify_mode(control::eHJustifyTypes::right);
    this->set_stretch_mode(0);
    this->set_margin(10);
    this->set_colour(ColorBackground);
    this->paint();

    character_strip* ctlFPS_Label = new character_strip();
    ctlFPS_Label->set_parent(this);
    std::string strSubCtrlName0 = "txtbxFPS_Label";
    ctlFPS_Label->set_name(strSubCtrlName0);
    ctlFPS_Label->set_font(control::_s_Fonts.get_font(0));
    ctlFPS_Label->set_colour(ColorLabelBackground);
    ctlFPS_Label->set_text_colour(ColorLabelForeground);
    ctlFPS_Label->set_data("FPS");
    this->add_child(ctlFPS_Label);
    ctlFPS_Label->paint();
    ctlFPS_Label = nullptr;

    character_strip* ctlFPS = new character_strip();
    ctlFPS->set_parent(this);
    std::string strSubCtrlName1 = "txtbxFPS";
    ctlFPS->set_name(strSubCtrlName1);
    ctlFPS->set_font(control::_s_Fonts.get_font(0));
    ctlFPS->set_colour(ColorLabelBackground);
    ctlFPS->set_text_colour(ColorLabelForeground);
    this->add_child(ctlFPS);
    ctlFPS->paint();
    ctlFPS = nullptr;

    character_strip* ctlFocusX_Label = new character_strip();
    ctlFocusX_Label->set_parent(this);
    std::string strSubCtrlName2 = "Focus_X_Label";
    ctlFocusX_Label->set_name(strSubCtrlName2);
    ctlFocusX_Label->set_font(control::_s_Fonts.get_font(0));
    ctlFocusX_Label->set_colour(ColorLabelBackground);
    ctlFocusX_Label->set_text_colour(ColorLabelForeground);
    ctlFocusX_Label->set_data("Focus X");
    this->add_child(ctlFocusX_Label);
    ctlFocusX_Label->paint();
    ctlFocusX_Label = nullptr;

    character_strip* ctlFocusX = new character_strip();
    ctlFocusX->set_parent(this);
    std::string strSubCtrlName3 = "Focus_X";
    ctlFocusX->set_name(strSubCtrlName3);
    ctlFocusX->set_font(control::_s_Fonts.get_font(0));
    ctlFocusX->set_colour(ColorLabelBackground);
    ctlFocusX->set_text_colour(ColorLabelForeground);
    this->add_child(ctlFocusX);
    ctlFocusX->paint();
    ctlFocusX = nullptr;

    character_strip* ctlFocusY_Label = new character_strip();
    ctlFocusY_Label->set_parent(this);
    std::string strSubCtrlName4 = "Focus_Y_Label";
    ctlFocusY_Label->set_name(strSubCtrlName4);
    ctlFocusY_Label->set_font(control::_s_Fonts.get_font(0));
    ctlFocusY_Label->set_colour(ColorLabelBackground);
    ctlFocusY_Label->set_text_colour(ColorLabelForeground);
    ctlFocusY_Label->set_data("Focus Y");
    this->add_child(ctlFocusY_Label);
    ctlFocusY_Label = nullptr;

    character_strip* ctlFocusY = new character_strip();
    ctlFocusY->set_parent(this);
    std::string strSubCtrlName15 = "Focus_Y";
    ctlFocusY->set_name(strSubCtrlName15);
    ctlFocusY->set_font(control::_s_Fonts.get_font(0));
    ctlFocusY->set_colour(ColorLabelBackground);
    ctlFocusY->set_text_colour(ColorLabelForeground);
    this->add_child(ctlFocusY);
    ctlFocusY = nullptr;

    character_strip* ctlFocusZ_Label = new character_strip();
    ctlFocusZ_Label->set_parent(this);
    std::string strSubCtrlName6 = "Focus_Z_Label";
    ctlFocusZ_Label->set_name(strSubCtrlName6);
    ctlFocusZ_Label->set_font(control::_s_Fonts.get_font(0));
    ctlFocusZ_Label->set_colour(ColorLabelBackground);
    ctlFocusZ_Label->set_text_colour(ColorLabelForeground);
    ctlFocusZ_Label->set_data("Focus Z");
    this->add_child(ctlFocusZ_Label);
    ctlFocusZ_Label = nullptr;

    character_strip* ctlFocusZ = new character_strip();
    ctlFocusZ->set_parent(this);
    std::string strSubCtrlName7 = "Focus_Z";
    ctlFocusZ->set_name(strSubCtrlName7);
    ctlFocusZ->set_font(control::_s_Fonts.get_font(0));
    ctlFocusZ->set_colour(ColorLabelBackground);
    ctlFocusZ->set_text_colour(ColorLabelForeground);
    this->add_child(ctlFocusZ);
    ctlFocusZ = nullptr;

    character_strip* ctlChunkCache_Label = new character_strip();
    ctlChunkCache_Label->set_parent(this);
    std::string strSubCtrlName8 = "Chunk_Cache_Label";
    ctlChunkCache_Label->set_name(strSubCtrlName8);
    ctlChunkCache_Label->set_width(150);
    ctlChunkCache_Label->set_font(control::_s_Fonts.get_font(0));
    ctlChunkCache_Label->set_colour(ColorLabelBackground);
    ctlChunkCache_Label->set_text_colour(ColorLabelForeground);
    ctlChunkCache_Label->set_data("Chunk Cache");
    this->add_child(ctlChunkCache_Label);
    ctlChunkCache_Label = nullptr;

    character_strip* ctlChunkCache = new character_strip();
    ctlChunkCache->set_parent(this);
    std::string strSubCtrlName9 = "Chunk_Cache";
    ctlChunkCache->set_name(strSubCtrlName9);
    ctlChunkCache->set_font(control::_s_Fonts.get_font(0));
    ctlChunkCache->set_colour(ColorLabelBackground);
    ctlChunkCache->set_text_colour(ColorLabelForeground);
    this->add_child(ctlChunkCache);
    ctlChunkCache = nullptr;

    this->paint();
}