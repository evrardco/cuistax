#include "cuistax.hxx"
#include "cui_errors.hxx"
#include "cui_debug.hxx"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

const char * cui_backend_str[] = {"Unknown", "SDL2"};

const char * cui_backend_to_str(cuistax_backend backend) {
    if (backend <= 0 || backend > 1) return cui_backend_str[0];
    return cui_backend_str[backend];
}

void cui_free_SDL(cui_SDL_context_t * ctx) {
    CUISTAX_LOG("Destroying SDL backend");
    SDL_DestroyWindow(ctx->window);
    SDL_DestroyRenderer(ctx->renderer);
    SDL_Quit();
}

cui_error_t cui_free(cui_context_t * ctx) {
    switch (ctx->backend_type) {
        case CUI_BACKEND_SDL2: {
            cui_free_SDL((cui_SDL_context_t *)&ctx->backend_ctx);
            return CUI_ERR_OK;
        }
        default: {
            CUISTAX_ERR("Unknown backend: %s", cui_backend_to_str(ctx->backend_type));
            return CUI_ERR_BACKEND_UNKNOWN;
        }
    }
}
cui_error_t cui_init(cui_context_t * ctx) {
    CUISTAX_LOG("Initializing backend: %s", cui_backend_to_str(ctx->backend_type));
    switch (ctx->backend_type) {
        case CUI_BACKEND_SDL2: {
        
            cui_SDL_context_t * sdl_ctx = (cui_SDL_context_t *)&ctx->backend_ctx;

            if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
                CUISTAX_ERR("SDL failed to initialise: %s\n", SDL_GetError());
                return CUI_ERR_SDL_INIT;
            }
            CUISTAX_LOG("Loaded SDL");
            
            sdl_ctx->window= SDL_CreateWindow(ctx->app_name, /* Title of the SDL window */
                            SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
                            SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
                            ctx->width, /* Width of the window in pixels */
                            ctx->height, /* Height of the window in pixels */
                            0); /* Additional flag(s) */

            if (sdl_ctx->window == NULL) {
                CUISTAX_ERR("SDL window failed to initialise: %s\n", SDL_GetError());
                return CUI_ERR_SDL_WINDOW;
            }
            SDL_Renderer * renderer = SDL_CreateRenderer(sdl_ctx->window, -1, SDL_RENDERER_ACCELERATED); 
            break;
        }
        default: {
            CUISTAX_ERR("Unknown backend: %s", cui_backend_to_str(ctx->backend_type));
            return CUI_ERR_BACKEND_UNKNOWN;
        }
    }
}