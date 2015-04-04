/* 
 * File:   biome_hills.cpp
 * Author: geth2k
 * 
 * Created on November 16, 2014, 12:36 AM
 */

#include "biome_hills.h"

biome_hills::biome_hills() {
}

biome_hills::biome_hills(int index, sid::height_map* height, sid::height_map* trees) :
sid::biome(index, height, trees) {
    this->__m_Color = sid::t_color(115, 240, 128, 255);
}

biome_hills::biome_hills(const biome_hills& orig) :
sid::biome(orig) {

}

biome_hills::~biome_hills() {

}

float biome_hills::get_height(int x, int y) const {
    float fHeight = (this->__m_HeightMap->get_height(x, y) + 1) / 2;
    fHeight *= 24;

    return fHeight;
}

