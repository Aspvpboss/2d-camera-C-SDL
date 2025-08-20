#pragma once
#include "common.h"

enum tileType{

    RED_TEXTURE,
    GREEN_TEXTURE,
    BLUE_TEXTURE,

};

struct MapTiles{

    SDL_Texture *texture;
    enum tileType type;

};
