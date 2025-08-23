#include "common.h"

#define FPS_POLL_RATE 1000

void calculate_dt(){

    static uint64_t previous = 0;
    static uint64_t frequency = 0;

    if (frequency == 0) {
        frequency = SDL_GetPerformanceFrequency();
        previous = SDL_GetPerformanceCounter();
        app.dt = 0.0;
        return;
    }

    uint64_t current = SDL_GetPerformanceCounter();
    app.dt = (double)(current - previous) / (double)frequency;
    previous = current;

}

void calculate_fps(){

    static int frame = 0;
    static double dt_buffer[FPS_POLL_RATE];

    if(frame < FPS_POLL_RATE){
        dt_buffer[frame] = app.dt;
        frame++;
        return;
    }

    double total = 0.0f;
    for(int i = 0; i < FPS_POLL_RATE; i++)
        total += dt_buffer[i];

    app.fps = 1 / (total / FPS_POLL_RATE);
    frame = 0;


    printf("\raverage fps: %f                ", app.fps);

    return;
}



SDL_AppResult SDL_AppIterate(void *appstate){

    calculate_dt();

    calculate_fps();

    if(update()){
        return SDL_APP_FAILURE;
    }

    if(render()){
        return SDL_APP_FAILURE;
    }
    
    return SDL_APP_CONTINUE;
}