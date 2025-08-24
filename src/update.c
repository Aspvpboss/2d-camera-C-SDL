#include "update.h"

void limit_x_position(){
    if(camera.x < 0)
        camera.x = 0;
    if(camera.x > map.width * app.texture_width - app.texture_width)
        camera.x = map.width * app.texture_width - app.texture_width;
} 

void limit_y_position(){
    if(camera.y < 0)
        camera.y = 0;
    if(camera.y > map.height * app.texture_height - app.texture_height)
        camera.y = map.height * app.texture_height - app.texture_height; 
}



int update(){

    const _Bool *keyboard = SDL_GetKeyboardState(NULL);

    if(keyboard[SDL_SCANCODE_W]){
        camera.y -= (camera.speed * app.dt);
        limit_y_position();
    }

    if(keyboard[SDL_SCANCODE_S]){

        camera.y += (camera.speed * app.dt);
        limit_y_position();
    }

    if(keyboard[SDL_SCANCODE_A]){

        camera.x -= (camera.speed * app.dt);
        limit_x_position();
    }

    if(keyboard[SDL_SCANCODE_D]){

        camera.x += (camera.speed * app.dt);
        limit_x_position();
    }

    return 0;
}