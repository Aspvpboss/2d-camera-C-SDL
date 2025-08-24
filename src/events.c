#include "common.h"

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){

    if(event->type == SDL_EVENT_QUIT){
        return SDL_APP_SUCCESS;
    }


    return SDL_APP_CONTINUE;
}
