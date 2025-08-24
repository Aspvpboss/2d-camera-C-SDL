#include "common.h"


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
    int FPS_POLL_RATE = app.max_fps_limit / 10;
    static int frame = 0;
    static double *dt_buffer = NULL;
    if(dt_buffer == NULL){
        dt_buffer = malloc(sizeof(double) * FPS_POLL_RATE);
    }


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

    printf("\raverage fps: %f                             ", app.fps);

    return;
}


void limit_fps(){

    static uint64_t last_counter = 0;
    static uint64_t freq = 0;

    if (freq == 0) {
        freq = SDL_GetPerformanceFrequency();
        last_counter = SDL_GetPerformanceCounter();
        return;
    }

    double target_frame_time = 1.0 / app.max_fps_limit;

    uint64_t now_counter = SDL_GetPerformanceCounter();
    double elapsed = (double)(now_counter - last_counter) / (double)freq;

    double remaining = target_frame_time - elapsed;

    if (remaining > 0) {
        if (remaining > 0.002) {
            SDL_Delay((Uint32)((remaining - 0.001) * 1000.0));
        }

        do {
            now_counter = SDL_GetPerformanceCounter();
            elapsed = (double)(now_counter - last_counter) / (double)freq;
        } while (elapsed < target_frame_time);
    }

    // Reset frame start
    last_counter = SDL_GetPerformanceCounter();

}



SDL_AppResult SDL_AppIterate(void *appstate){

    if(update()){
        return SDL_APP_FAILURE;
    }

    if(render()){
        return SDL_APP_FAILURE;
    }

    limit_fps();
    calculate_dt();
    calculate_fps();
    
    return SDL_APP_CONTINUE;
}