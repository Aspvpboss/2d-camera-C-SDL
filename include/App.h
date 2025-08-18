#pragma once


typedef struct{

    SDL_Window *window;
    SDL_Renderer *renderer;
    int width, height;
    SDL_WindowFlags windowFlags;
 
}App;