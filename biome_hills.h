/* 
 * File:   biome_hills.h
 * Author: geth2k
 *
 * Created on November 16, 2014, 12:36 AM
 */

#ifndef BIOME_HILLS_H
#define	BIOME_HILLS_H

#include "../3DOAPI_0_1/SID_plot.h"
#include "../3DOAPI_0_1/SID_biome.h"

class biome_hills : public sid::biome {
public:
    biome_hills();
    biome_hills(int index, sid::height_map* height, sid::height_map* trees);
    biome_hills(const biome_hills& orig);
    virtual ~biome_hills();
    
    virtual float get_height(int x, int y) const;
private:

};

#endif	/* BIOME_HILLS_H */

