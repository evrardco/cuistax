#pragma once
#include <limits.h>
typedef enum cui_error {
    CUI_ERR_SDL_INIT = INT_MIN,
    CUI_ERR_SDL_WINDOW,
    CUI_ERR_SDL_TEXTURE,
    CUI_ERR_OK = 0
} cui_error_t ;