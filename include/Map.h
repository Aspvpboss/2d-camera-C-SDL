#pragma once
#include "common.h"


typedef struct{

    struct MapTiles **map;
    int width, height;

    SDL_Texture *red_texture;
    SDL_Texture *green_texture;
    SDL_Texture *blue_texture;

} Map;