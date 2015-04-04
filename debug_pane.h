/* 
 * File:   debug_pane.h
 * Author: geth2k
 *
 * Created on 05 December 2013, 23:57
 */

#ifndef DEBUG_PANE_H
#define	DEBUG_PANE_H

#include "../3DOAPI_0_1/SID_control.h"
#include "../3DOAPI_0_1/SID_character_strip.h"

using namespace sid;

class debug_pane : public control {
public:
    debug_pane();
    debug_pane(const debug_pane& orig);
    virtual ~debug_pane();
    
protected:
    void setup_ui();
        
private:

};

#endif	/* DEBUG_PANE_H */

