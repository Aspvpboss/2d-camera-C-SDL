#include "common.h"


SDL_AppResult SDL_AppIterate(void *appstate){

    if(render()){
        return SDL_APP_FAILURE;
    }
    
    return SDL_APP_CONTINUE;
}