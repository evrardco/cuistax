#pragma once
#include <SDL2/SDL.h>

class TextureRect {
    public:
        TextureRect(SDL_Texture * texture, int x, int y, int w, int h); 
        void draw_to(SDL_Renderer * renderer, SDL_Rect * dest);
        SDL_Rect * get_source();
        double get_texture_x();
        double get_texture_y();
        double get_texture_width();
        double get_texture_height();
        void set_texture_x(double x);
        void set_texture_y(double y);
        void set_texture_width(double w);
        void set_texture_height(double h);

    protected:
        SDL_Texture * texture;
        SDL_Rect source;
    private:
};
