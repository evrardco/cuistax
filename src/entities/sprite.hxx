#pragma once
#include "../base/entity.hxx"
#include "../utils/graphics/TextureRect.hxx"

class Sprite : public Entity {
    public:
        Sprite(double x, double y, TextureRect * texrec);
        void draw(SDL_Renderer * renderer);
        void step(double dt);
    protected:
        SDL_Rect destination;
        TextureRect * texrec;
    private:
};



