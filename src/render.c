#include "render.h"



int render(){

    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);

    SDL_FRect dst;
    
    for(int y = 0; y < map.height; y++){

        for(int x = 0; x < map.width; x++){

            dst.x = x * app.texture_width; 
            dst.y = y * app.texture_height; 
            dst.w = app.texture_width;
            dst.h = app.texture_height;
            SDL_RenderTexture(app.renderer, map.map[y][x].texture, NULL, &dst);

        }
    }


    SDL_RenderPresent(app.renderer);

    return 0;
}