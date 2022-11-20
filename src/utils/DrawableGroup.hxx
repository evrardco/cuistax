#pragma once
#include <vector>
#include "../base/drawable.hxx"
class DrawableGroup : public std::vector<Drawable *>, public Drawable {
    public:
     void draw(SDL_Renderer * renderer);
     ~DrawableGroup();
     private:
};