/*
 * File:   game.cpp
 * Author: geth2k
 *
 * Created on 29 November 2013, 19:37
 */

#include "game.h"

game::game() {


#ifdef DEBUG
    this->_m_Display = new sid::display(
            "Children Of Orion 0.1 (Debug)",
            960,
            600,
            0,
            false);
#else
    this->_m_Display = new display("Children Of Orion 0.1 (Release)",
            1280,
            800,
            0,
            true);
#endif
    if (!this->_m_Display->is_initialised()) {
        sid::SID_Quit();
        exit(1);
    }

    float fClearColor[4] = {0.0, 0.0, 0.1, 1.0};
    sid::init_GL(90.0, 2000,
            fClearColor[0], fClearColor[1], fClearColor[2], fClearColor[3],
            this->_m_Display->get_window_width(),
            this->_m_Display->get_window_height(),
            this->_m_Display->get_aspect_ratio());

    this->_m_Forms = new sid::forms();
}

game::game(const game& orig) : api(orig) {

}

game::~game() {
}

/*
 *
 */
void game::init_engine() {
    this->_m_Camera->set_center_screen(this->_m_Display->get_window_width(),
            this->_m_Display->get_window_height());

    std::string strTexPath2 = "./assets/textures/loading_screen.png";
    object::add_texture(strTexPath2, 1, 0);
    this->_m_Forms->add_form(new loading_screen());
    sid::init_frame_2d();
    this->render_2d();
    this->_m_Display->swap_buffers();

    this->load_gametextures();
    this->load_fonts();
    this->load_music();
    SDL_Delay(2000);
    this->_m_Forms->remove_form("loading_screen");
    sid::init_frame_3d(60, 2000);
    this->render_3d();
    this->render_2d();
    this->_m_Display->swap_buffers();

}

void game::build_main_menu() {
    this->_m_Forms->add_form(new main_menu());
    this->_m_Forms->at("main_menu")->paint();
}

/*
 *
 */
void game::run_gameloop() {
    
    float fSeedBase = perlin::gen_seed();
    sid::perlin* BaseHeight = new perlin(0.03, 2.0, 0.20, 3, fSeedBase);
    sid::perlin* BaseTrees = new perlin(0.1, 1.0, 0.70, 3, fSeedBase);
    sid::perlin* DefaultHeight = new perlin(0.12, 2.0, 0.30, 8, fSeedBase);
    sid::perlin* DefaultTrees = new perlin(0.1, 1.0, 0.70, 3, fSeedBase);
    sid::perlin* HillsHeight = new perlin(0.2, 2.0, 0.2, 3, fSeedBase);
    sid::perlin* HillsTrees = new perlin(0.1, 1.0, 0.70, 3, fSeedBase);    

    chunk::s_Biomes.add_biome(new biome_land_mass(0, BaseHeight, BaseTrees));
    chunk::s_Biomes.add_biome(new biome_default(1, DefaultHeight, DefaultTrees));
    chunk::s_Biomes.add_biome(new biome_hills(2, HillsHeight, HillsTrees));

    this->_m_Environs = new sid::environs(15);
    chunk::s_Biomes.set_seed(fSeedBase);
    
    this->build_terrain();

    vertex3 vtxCamFocus = this->_m_Camera->get_focus_pos();
    plot* pltCamFocus = this->_m_Environs->get_plot_at(vtxCamFocus);
    float fFocusHeight = pltCamFocus->get_position().data()[euclid::DIMENSION_Y];
    this->_m_Camera->set_zoom_to(pltCamFocus->get_position());
    
    this->add_ingame_menus();
    this->add_debug_form();

    this->m_clkFPS.update_timediff();
    this->m_clkTimeDiff.update_timediff();
    this->_m_Environs->tick();

    clickmode_panel* ctlModeCorner;
    ctlModeCorner = static_cast<clickmode_panel*> (
            this->_m_Forms->at("clickmode_panel"));

    while (!this->is_game_stopped()) {
        this->m_clkTimeDiff.update_timediff();

        int iMouseMode = ctlModeCorner->get_mouse_mode();
        this->_m_Environs->set_mouse_mode(iMouseMode);

        this->build_terrain();

        this->render_3d();

        this->process_event();

        this->_m_Environs->draw_selection2();

        this->_m_Environs->zoom_to_plot(this->m_clkTimeDiff.get_delta(), this->_m_Camera);

        this->render_2d();

        this->_m_Display->swap_buffers();

        this->_m_Environs->tick();
#ifdef DEBUG
        if (!this->is_paused()) {
            set_debug_info();
        }
#endif
    }

    this->_m_Forms->clear_forms();

    if (this->_m_Environs) {
        delete this->_m_Environs;
        this->_m_Environs = nullptr;
    }

    chunk::s_Biomes.clear();

    std::cout << "Exiting Game Loop" << std::endl;
}

/*
 *
 */
void game::load_gametextures() {
    std::string strTexPath500 = "./assets/textures/terrain1.png";
    object::add_texture(strTexPath500, 500, texture::SID_TEX_FLAG_GEN_MIPMAPS);

    std::string strTexPath100 = "./assets/textures/objbrows_bg.png";
    std::string strTexPath101 = "./assets/textures/menubar_bg.png";
    std::string strTexPath102 = "./assets/textures/mode_corner.png";
    std::string strTexPath103 = "./assets/textures/btn_clickmode_fight_off.png";
    std::string strTexPath104 = "./assets/textures/btn_clickmode_fight_on.png";
    std::string strTexPath105 = "./assets/textures/btn_clickmode_build_off.png";
    std::string strTexPath106 = "./assets/textures/btn_clickmode_build_on.png";
    std::string strTexPath107 = "./assets/textures/btn_clickmode_terrain_off.png";
    std::string strTexPath108 = "./assets/textures/btn_clickmode_terrain_on.png";
    std::string strTexPath109 = "./assets/textures/btn_clickmode_query_off.png";
    std::string strTexPath110 = "./assets/textures/btn_clickmode_query_on.png";

    object::add_texture(strTexPath100, 100, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);
    object::add_texture(strTexPath101, 101, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);
    object::add_texture(strTexPath102, 102, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);
    object::add_texture(strTexPath103, 103, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);
    object::add_texture(strTexPath104, 104, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);
    object::add_texture(strTexPath105, 105, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);
    object::add_texture(strTexPath106, 106, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);
    object::add_texture(strTexPath107, 107, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);
    object::add_texture(strTexPath108, 108, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);
    object::add_texture(strTexPath109, 109, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);
    object::add_texture(strTexPath110, 110, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);

    std::string strTexPath2 = "./assets/textures/main_menu_bg.png";
    object::add_texture(strTexPath2, 2, texture::SID_TEX_FLAG_GEN_MIPMAPS);
    
    sid::sidof* sidofCube = new sid::sidof("./assets/models/cube.sido");
    sid::object_ingame::add_template(0, sidofCube);
    delete sidofCube;
}

/*
 *
 */
void game::load_fonts() {
    /* To Do: overload add_textures so that uiTexID can be passed by reference
     * and updated while texture is loaded. This should be much faster than 
     * searching for it, as coded below. */
    std::string strTexPath1 = "./assets/textures/font1_small.png";
    this->_m_Forms->Textures.add_texture(strTexPath1, 1000, texture::SID_TEX_FLAG_MULTIPLY_ALPHA);
    uint uiTexID = this->_m_Forms->Textures.get_tex_id_by_ref(1000);

    std::string strFntPath1 = "fontmap1.ftm";
    fonts* fnts = new fonts();

    control::add_font(strFntPath1, 0, uiTexID);
}

/*
 *
 */
void game::load_music() {
    object::add_sound("btnclk.wav", 100);

    object::add_song("All This.mp3", 100);
    object::add_song("Ticks & Leeches.mp3", 101);
}

/*
 *
 */
void game::add_ingame_menus() {
    this->_m_Forms->add_form(new game_menu());

    this->_m_Forms->add_form(new mission_planner());

    this->_m_Forms->add_form(new clickmode_panel());

    this->_m_Forms->add_form(new pause_menu());
}

void game::add_debug_form() {
    debug_pane* DebugPane;
    DebugPane = new debug_pane();
    std::vector<int> viWidths;
    viWidths.push_back(125);
    viWidths.push_back(65);
    layout* lyt = new layout(22, viWidths, 0);
    DebugPane->set_layout(lyt);
    DebugPane->paint();
    this->_m_Forms->add_form(DebugPane);
}

void game::set_debug_info() {
    static uint uiFramesInSecond;
    uiFramesInSecond++;
    float fFPS;

    this->m_clkFPS.update_timediff();

    debug_pane* DebugPane;
    std::string sSearchString;
    DebugPane = static_cast<debug_pane*> (this->_m_Forms->at("Debug"));
    if (this->m_clkFPS.get_time() >= 1) {
        ostringstream convert;
        convert.precision(3);
        fFPS = uiFramesInSecond / this->m_clkFPS.get_time();
        uiFramesInSecond = 0;
        this->m_clkFPS.adjust_time(-1.0);
        convert << fFPS;

        sSearchString = "txtbxFPS";
        control* ctrlFPS = static_cast<control*> (
                DebugPane->get_child(sSearchString));

        ctrlFPS->set_data(convert.str());
    }
    
    sid::vertex3 vtxFocusPos = this->_m_Camera->get_focus_pos();

    sSearchString = "Focus_X";
    control* ctlFocusX = static_cast<control*> (
            DebugPane->get_child(sSearchString));
    ostringstream convertFocusX;
    convertFocusX << vtxFocusPos[euclid::DIMENSION_X];
    ctlFocusX->set_data(convertFocusX.str());

    sSearchString = "Focus_Y";
    control* ctlFocusY = static_cast<control*> (
            DebugPane->get_child(sSearchString));
    ostringstream convertFocusY;
    convertFocusY << vtxFocusPos[euclid::DIMENSION_Y];
    ctlFocusY->set_data(convertFocusY.str());

    sSearchString = "Focus_Z";
    control* ctlFocusZ = static_cast<control*> (
            DebugPane->get_child(sSearchString));
    ostringstream convertFocusZ;
    convertFocusZ << vtxFocusPos[euclid::DIMENSION_Z];
    ctlFocusZ->set_data(convertFocusZ.str());

    sSearchString = "Chunk_Cache";
    control* ctlChunkCache = static_cast<control*> (
            DebugPane->get_child(sSearchString));
    ostringstream convertChunkCache;
    convertChunkCache << this->_m_Environs->get_chunk_cache_count();
    ctlChunkCache->set_data(convertChunkCache.str());
}

void game::pause_game() {
    this->_m_Forms->show_form("pause_menu");
    this->_m_Forms->control_to_front("pause_menu");
}

void game::unpause_game() {
    this->_m_Forms->hide_form("pause_menu");
}
