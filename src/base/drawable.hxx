#pragma once
#include <SDL2/SDL.h>
class Drawable {
    public:
        virtual void draw(SDL_Renderer *) = 0;
        virtual double get_x();
        virtual double get_y();
        virtual void set_x(double);
        virtual void set_y(double);
    protected:
        double x;
        double y;
    private:
};