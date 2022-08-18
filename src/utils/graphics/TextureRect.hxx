#pragma once
#include <SDL2/SDL.h>

class TextureRect {
    public:
        TextureRect(SDL_Texture * texture, int x, int y, int w, int h); 
        void draw_to(SDL_Renderer * renderer, SDL_Rect * dest);
        SDL_Rect * get_source();
    protected:
        SDL_Texture * texture;
        SDL_Rect source;
    private:
};
