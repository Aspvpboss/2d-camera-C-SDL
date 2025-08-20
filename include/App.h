#pragma once
#include "common.h"


typedef struct{

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_WindowFlags windowFlags;
    int width, height;
    int texture_width, texture_height;
 
}App;