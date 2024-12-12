#include "SDL_stdinc.h"
#include "SDL_timer.h"
#include "stage.hxx"
#include <bits/types/struct_timeval.h>
#include <sys/time.h>
//the internal playing flag
static bool _playing = false;

bool Stage::set_playing(bool playing) {
    //TODO Implement
    return true;
}

bool Stage::is_playing() {
    //TODO Implement
    return false;
}

void engine_loop(Stage * stage, cui_backend_context_t * back_ctx) {
    double frame_time = (1.0f / stage->get_target_fps());
    bool keep_window_open = true;
    SDL_Renderer * renderer = back_ctx->ctx_SDL.renderer;
    timeval t0, t1;
    double dt = 0;
    double total_time = 0;
    uint32_t dt_millis;
    uint32_t delay_time;
    SDL_Event e;
    bool fps_limited = stage->get_target_fps() > -1;
    Scene scene = *(stage->get_current_scene());

    gettimeofday(&t0, NULL);

    while(keep_window_open) {
        while(SDL_PollEvent(&e) > 0)
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
                case SDL_KEYDOWN:
                    //handle_keydown(&e, player);
                    break;
                case SDL_KEYUP:
                    //handle_keyup(&e, player);
                    break;
            }
        }

        gettimeofday(&t1, NULL);
        
        dt = (double)(t1.tv_usec - t0.tv_usec) / 1000000 + (double)(t1.tv_sec - t0.tv_sec);
        while (fps_limited && (frame_time > dt)) {
            gettimeofday(&t1, NULL);
            dt = (double)(t1.tv_usec - t0.tv_usec) / 1000000 + (double)(t1.tv_sec - t0.tv_sec);
        }
        t0 = t1;
        scene.step(dt);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        //TODO Move the color out of the loop
        SDL_RenderClear(renderer);

        scene.draw(renderer);
        SDL_RenderPresent(renderer);



        

    }   

}