#define SDL_MAIN_USE_CALLBACKS 1

#include "common.h"
#include <SDL3/SDL_main.h>

App app;


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){

    app.width = 800;
    app.height = 800;
    app.windowFlags = SDL_WINDOW_MAXIMIZED;

    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("Failed to intialize: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if(!SDL_CreateWindowAndRenderer("SDL_WINDOW", app.width, app.height, app.windowFlags, &app.window, &app.renderer)){
        SDL_Log("Failed to create renderer or window: %s", SDL_GetError());
        return SDL_APP_FAILURE;        
    }
    
    return SDL_APP_CONTINUE;
}