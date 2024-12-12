#pragma once
#define CUISTAX_VERSION "0.1"
#include "SDL2/SDL.h"
#include "cui_errors.hxx"
#define MAX_APP_NAME_SIZE 128 
typedef enum {
    CUI_BACKEND_SDL2 = 1
} cuistax_backend;


typedef struct cui_SDL_context {
    SDL_Window * window;
    SDL_Renderer * renderer;
    cuistax_backend backend;
} cui_SDL_context_t;

typedef union {
    cui_SDL_context_t ctx_SDL;
} cui_backend_context_t;

typedef struct {
    char app_name[MAX_APP_NAME_SIZE];
    int width;
    int height;
    unsigned int fps;
    cui_backend_context_t backend_ctx;
    cuistax_backend backend_type;
} cui_context_t;

const char * cui_backend_to_str(cuistax_backend backend);
void cui_free_SDL(cui_SDL_context_t *);
cui_error_t cui_init(cui_context_t *, int width, int height, const char * app_name);