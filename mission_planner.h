/* 
 * File:   mission_planner.h
 * Author: geth2k
 *
 * Created on 06 December 2013, 02:06
 */

#ifndef MISSION_PLANNER_H
#define	MISSION_PLANNER_H

#include "../3DOAPI_0_1/SID_control.h"
#include "../3DOAPI_0_1/SID_button.h"

using namespace sid;

class mission_planner : public control {
public:
    mission_planner();
    mission_planner(const mission_planner& orig);
    virtual ~mission_planner();

private:
    virtual void setup_ui();

};

#endif	/* MISSION_PLANNER_H */

