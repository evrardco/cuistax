#pragma once
#include <SDL2/SDL_render.h>
#include <cstdint>
#include <SDL2/SDL.h>
#define CUISTAX_VERSION_NUMBER 0
#define CUISTAX_VERSION_MAJOR 2
#define CUISTAX_VERSION_MINOR 1
#ifndef CUI_LOG_LEVEL
#define CUI_LOG_LEVEL 4
#endif
#ifdef CUI_DISABLE_LOG
#define CUI_ERR(fmt_str, ...) ;
#define CUI_WARN(fmt_str, ...) ;
#define CUI_LOG(fmt_str, ...) ;
#define CUI_DEBUG(fmt_str, ...) ;
#else
#define CUI_ERR(fmt_str, ...) if ((CUI_LOG_LEVEL > 0)) printf("[ERROR]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
#define CUI_WARN(fmt_str, ...) if ((CUI_LOG_LEVEL > 1)) printf("[WARNING]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__ )
#define CUI_LOG(fmt_str, ...) if ((CUI_LOG_LEVEL) > 2) printf("[LOG]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
#define CUI_DEBUG(fmt_str, ...) if ((CUI_LOG_LEVEL > 3)) printf("[DEBUG]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
#endif


typedef enum {
    CUI_BACKEND_SDL2
} cui_backend;

typedef struct {
    uint16_t width;
    uint16_t height;
} resolution_t;

typedef struct {
    uint16_t num;
    uint16_t den;
} framerate_t;

typedef struct {
    cui_backend backend;
    resolution_t resolution;
    framerate_t framerate;
    const char * window_title;
} cui_context_t;

typedef struct {
    cui_context_t * ctx;
    //TODO After adding more backends: add a struct with union and enum for backend switching
    SDL_Window * window;
    SDL_Renderer * renderer;
} cuistax_t;

cuistax_t * cuistax_init(cui_context_t * ctx);