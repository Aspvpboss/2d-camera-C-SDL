#include "common.h"

void SDL_AppQuit(void *appstate, SDL_AppResult result){

    for(int i = 0; i < map.height; i++)
        free(map.map[i]);
    free(map.map);
    
}