#include "DrawableGroup.hxx"
void DrawableGroup::draw(SDL_Renderer * renderer) {
    for (auto d = this->begin(); d != this->end(); d++) {
        (*d)->draw(renderer);
    }
}
DrawableGroup::~DrawableGroup() {
    for (auto d = this->begin(); d != this->end(); d++) {
        delete *d;
    }
}