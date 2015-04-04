/* 
 * File:   biome_land_mass.h
 * Author: geth2k
 *
 * Created on July 8, 2014, 12:21 AM
 */

#ifndef BIOME_LAND_MASS_H
#define	BIOME_LAND_MASS_H

#include "../3DOAPI_0_1/SID_plot.h"
#include "../3DOAPI_0_1/SID_biome.h"

class biome_land_mass : public sid::biome {
public:
    biome_land_mass();
    biome_land_mass(int index, sid::height_map* height, sid::height_map* trees);
    biome_land_mass(const biome_land_mass& orig);
    virtual ~biome_land_mass();
    
    virtual float get_height(int x, int y) const;
private:

};

#endif	/* BIOME_LAND_MASS_H */

