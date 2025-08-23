#include "update.h"


int update(){

    camera.tile_x = camera.x / app.texture_width;
    camera.tile_y = camera.y / app.texture_height;

    return 0;
}