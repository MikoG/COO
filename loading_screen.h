/* 
 * File:   loading_screen.h
 * Author: geth2k
 *
 * Created on June 7, 2014, 11:04 PM
 */

#ifndef LOADING_SCREEN_H
#define	LOADING_SCREEN_H

#include "../3DOAPI_0_1/SID_control.h"

using namespace sid;

class loading_screen : public control {
public:
    loading_screen();
    loading_screen(const loading_screen& orig);
    virtual ~loading_screen();
    
    virtual void setup_ui();
    
private:

};

#endif	/* LOADING_SCREEN_H */

