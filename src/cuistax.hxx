#pragma once
#define CUISTAX_VERSION "0.1"
#include "SDL2/SDL.h"
#include "utils/cui_errors.hxx"

typedef struct cui_SDL_context {
    SDL_Window * window;
    SDL_Renderer * renderer;
} cui_SDL_context_t;

typedef struct cui_config {
    int width;
    int height;
} cui_config_t;
void cui_free_SDL(cui_SDL_context_t *);
cui_error_t cui_init(cui_config_t *);