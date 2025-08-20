#define SDL_MAIN_USE_CALLBACKS 1

#include "common.h"
#include <SDL3/SDL_main.h>

App app;
Map map;


int app_init(App *app){

    app->width = 800;
    app->height = 800;
    app->texture_height = 50;
    app->texture_width = 50;
    app->windowFlags = SDL_WINDOW_MAXIMIZED;


    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("Failed to intialize: %s", SDL_GetError());
        return 1;
    }

    if(!SDL_CreateWindowAndRenderer("SDL_WINDOW", app->width, app->height, app->windowFlags, &app->window, &app->renderer)){
        SDL_Log("Failed to create renderer or window: %s", SDL_GetError());
        return 1;        
    }

    return 0;
}



int map_init(Map *map){

    map->width = 20;
    map->height = 20;
    map->map = malloc(sizeof(struct MapTiles) * map->height);

    if(map->map == NULL)
        return 1;

    for(int i = 0; i < map->height; i++){
        map->map[i] = malloc(sizeof(struct MapTiles) * map->width);

        if(map->map[i] == NULL)
            return 1;
    }

    return 0;
}



int textures_init(Map *map){

    SDL_Surface *red_surface = SDL_LoadBMP("./assets/red.bmp");
    SDL_Surface *green_surface = SDL_LoadBMP("./assets/green.bmp");
    SDL_Surface *blue_surface = SDL_LoadBMP("./assets/blue.bmp");

    if(!red_surface || !green_surface || !blue_surface){
        printf("failed to load bmp images\n");
        return 1;
    }

    map->red_texture = SDL_CreateTextureFromSurface(app.renderer, red_surface);
    map->green_texture = SDL_CreateTextureFromSurface(app.renderer, green_surface);
    map->blue_texture = SDL_CreateTextureFromSurface(app.renderer, blue_surface);
    
    SDL_DestroySurface(red_surface);
    SDL_DestroySurface(blue_surface);
    SDL_DestroySurface(green_surface);

    //bad
    for(int y = 0; y < map->height; y++){

        struct MapTiles *row = map->map[y];

        for(int x = 0; x < map->width; x++){

            if(y % 2 == 0){

                if(x % 3 == 0){
                    row[x].type = RED_TEXTURE;
                } else if (x % 2 == 0){
                    row[x].type = GREEN_TEXTURE;
                } else{
                    row[x].type = BLUE_TEXTURE;
                }

            } else{

                if(x % 3 == 0){
                    row[x].type = BLUE_TEXTURE;
                } else if (x % 2 == 0){
                    row[x].type = RED_TEXTURE;
                } else{
                    row[x].type = GREEN_TEXTURE;
                }

            }

            switch(row[x].type){

                case(RED_TEXTURE):
                    row[x].texture = map->red_texture;
                    break;

                case(GREEN_TEXTURE):
                    row[x].texture = map->green_texture;
                    break;

                case(BLUE_TEXTURE):
                    row[x].texture = map->blue_texture;
                    break;

            }
        }
    }

 


    return 0;
}



SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){

    if(app_init(&app))
        return SDL_APP_FAILURE;

    if(map_init(&map)){
        return SDL_APP_FAILURE;
    }

    if(textures_init(&map)){
        return SDL_APP_FAILURE;
    }
    
    


    return SDL_APP_CONTINUE;
}