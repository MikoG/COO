/* 
 * File:   clickmode_panel.h
 * Author: geth2k
 *
 * Created on 18 March 2014, 22:37
 */

#ifndef CLICKMODE_PANEL_H
#define	CLICKMODE_PANEL_H

#include "../3DOAPI_0_1/SID_control.h"
#include "../3DOAPI_0_1/SID_radio_button.h"

class clickmode_panel : public sid::control {
public:
    clickmode_panel();
    clickmode_panel(const clickmode_panel& orig);
    virtual ~clickmode_panel();
    
    void set_mouse_mode(int clickMode);
    int get_mouse_mode() const;
    
    sid::radio_button::rb_group* m_rbgMouseModes;
    sid::radio_button* m_ctlFightMode;
    sid::radio_button* m_ctlBuildMode;
    sid::radio_button* m_ctlTerrainMode;
    sid::radio_button* m_ctlQueryMode;
    
protected:
    virtual void setup_ui();
    
    int m_iMouseMode;
        
private:

};

void toggle_fight_mouse_up(sid::object* sender, SDL_Event& evt);

void toggle_build_mouse_up(sid::object* sender, SDL_Event& evt);

void toggle_terrain_mouse_up(sid::object* sender, SDL_Event& evt);

void toggle_query_mouse_up(sid::object* sender, SDL_Event& evt);

#endif	/* CLICKMODE_PANEL_H */

