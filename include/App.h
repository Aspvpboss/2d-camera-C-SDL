#pragma once



typedef struct{

    SDL_Window *window;
    SDL_Renderer *renderer;
    int width, height;
    bool fullscreen;
 
}App;