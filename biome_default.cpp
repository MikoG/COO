/* 
 * File:   biome_default.cpp
 * Author: geth2k
 * 
 * Created on July 8, 2014, 1:16 AM
 */

#include "biome_default.h"

biome_default::biome_default() {
}

biome_default::biome_default(int index, sid::height_map* height, sid::height_map* trees) : 
sid::biome(index, height, trees) {
    this->__m_Color = sid::t_color(115, 240, 128, 255);
}

biome_default::biome_default(const biome_default& orig) {
}

biome_default::~biome_default() {
}

float biome_default::get_height(int x, int y) const {
    float fPerlin = this->__m_HeightMap->get_height(x, y);
    float fRetVal = ((fPerlin + 1) / 2 * 16);
    return fRetVal;
}