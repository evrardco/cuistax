#include "DrawableGroup.hxx"
void DrawableGroup::draw(SDL_Renderer * renderer) {
    for (auto d = this->begin(); d != this->end(); d++) {
        (*d)->draw(renderer);
    }
}
