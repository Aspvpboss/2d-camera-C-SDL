#pragma once
#include "common.h"

typedef struct{

    SDL_Texture *texture;
    float x, y;
    int width, height;
    int tile_x, tile_y;
    int speed;

} Camera;

