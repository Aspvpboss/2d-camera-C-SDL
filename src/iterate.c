#include "common.h"


SDL_AppResult SDL_AppIterate(void *appstate){

    SDL_RenderPresent(app.renderer);
    
    return SDL_APP_CONTINUE;
}