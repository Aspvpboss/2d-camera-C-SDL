#include "render.h"

static SDL_FRect dst;

int render(){

    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
    SDL_RenderClear(app.renderer);

    int cam_minimum_width = camera.tile_x - camera.width;
    if(cam_minimum_width < 0)
        cam_minimum_width = 0;
    
    int cam_maximum_width = camera.tile_x + camera.width;
    if(cam_maximum_width > map.width)
        cam_maximum_width = map.width;

    int cam_minimum_height = camera.tile_y - camera.height;
    if(cam_minimum_height < 0)
        cam_minimum_height = 0;
    
    int cam_maximum_height = camera.tile_y + camera.height;
    if(cam_maximum_height > map.height)
        cam_maximum_height = map.height;

    camera.tile_x = camera.x / app.texture_width;
    camera.tile_y = camera.y / app.texture_height;
    int screen_width_half = app.width / 2;
    int screen_height_half = app.height / 2;

    for(int y = cam_minimum_height; y < cam_maximum_height; y++){

        for(int x = cam_minimum_width; x < cam_maximum_width; x++){
            
            dst.x = (float)((x * app.texture_width - camera.x) + screen_width_half); 
            dst.y = (float)((y * app.texture_height - camera.y) + screen_height_half); 
            dst.w = app.texture_width;
            dst.h = app.texture_height;
            SDL_RenderTexture(app.renderer, map.map[y][x].texture, NULL, &dst);

        }
    }

    dst.x = app.width / 2; 
    dst.y = app.height / 2; 

    SDL_RenderTexture(app.renderer, camera.texture, NULL, &dst);


    SDL_RenderPresent(app.renderer);

    return 0;
}