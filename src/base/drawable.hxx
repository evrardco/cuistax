#pragma once
#include <SDL2/SDL.h>
class Drawable {
    public:
        virtual void draw() = 0;
        virtual double get_x();
        virtual double get_y();
        virtual void set_x(double);
        virtual void set_y(double);
        virtual SDL_Renderer * get_renderer();
    protected:
        SDL_Renderer *renderer;
        double x;
        double y;
    private:
};