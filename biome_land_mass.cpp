/* 
 * File:   biome_land_mass.cpp
 * Author: geth2k
 * 
 * Created on July 8, 2014, 12:21 AM
 */

#include "biome_land_mass.h"

biome_land_mass::biome_land_mass() {
}

biome_land_mass::biome_land_mass(int index, sid::height_map* height,
        sid::height_map* trees) :
sid::biome(index, height, trees) {
    this->__m_Color = sid::t_color(115, 240, 128, 255);
}

biome_land_mass::biome_land_mass(const biome_land_mass& orig) :
sid::biome(orig) {
}

biome_land_mass::~biome_land_mass() {
}

float biome_land_mass::get_height(int x, int y) const {
    float fHeight = this->__m_HeightMap->get_height(x, y);
    
    float fLandHeight = sid::plot::SEA_LEVEL + 4;

    fHeight = (fHeight + 1) / 2 * 255;
    
    float fDepth = fLandHeight - fHeight;

    if (fHeight > fLandHeight) {
        fHeight = fLandHeight;
    } else {
        fHeight = fLandHeight - fDepth / 2;
    }

    return fHeight;
}