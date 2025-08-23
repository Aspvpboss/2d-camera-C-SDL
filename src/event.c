#include "common.h"

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){

    if(event->type == SDL_EVENT_QUIT){
        return SDL_APP_SUCCESS;
    }

    switch(event->key.scancode){



        case(SDL_SCANCODE_W):

            camera.y -= (50000 * app.dt);
            if(camera.y < 0)
                camera.y = 0;
            if(camera.y > map.height * app.texture_height)
                camera.y = map.height * app.texture_height;

            break;

        case(SDL_SCANCODE_S):

            camera.y += (50000 * app.dt);
            if(camera.y < 0)
                camera.y = 0;
            if(camera.y > map.height * app.texture_height)
                camera.y = map.height * app.texture_height;

            break;

        case(SDL_SCANCODE_A):

            camera.x -= (50000 * app.dt);
            if(camera.x < 0)
                camera.x = 0;
            if(camera.x > map.width * app.texture_width)
                camera.x = map.width * app.texture_width;

            break;

        case(SDL_SCANCODE_D):

            camera.x += (50000 * app.dt);
            if(camera.x < 0)
                camera.x = 0;
            if(camera.x > map.width * app.texture_width)
                camera.x = map.width * app.texture_width;

            break;

        default:
            break;
    }

    return SDL_APP_CONTINUE;
}
