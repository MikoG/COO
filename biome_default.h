/* 
 * File:   biome_default.h
 * Author: geth2k
 *
 * Created on July 8, 2014, 1:16 AM
 */

#ifndef BIOME_DEFAULT_H
#define	BIOME_DEFAULT_H

#include <iostream>

#include "../3DOAPI_0_1/SID_biome.h"

class biome_default : public sid::biome {
public:
    biome_default();
    biome_default(int index, sid::height_map* height, sid::height_map* trees);
    biome_default(const biome_default& orig);
    virtual ~biome_default();
    
    virtual float get_height(int x, int y) const;
    
private:

};

#endif	/* BIOME_DEFAULT_H */

