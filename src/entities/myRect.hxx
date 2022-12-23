#pragma once
#include "../base/entity.hxx"
#include "SDL2/SDL.h"
class MyRect : public Entity {
    public:
        MyRect(double, double, int, int);
        void step(double) override;
        void draw(SDL_Renderer *) override;
        int get_width();
        int get_height();
        void set_width(int);
        void set_height(int);
    protected:
        SDL_Rect rect;
    private:
        
};