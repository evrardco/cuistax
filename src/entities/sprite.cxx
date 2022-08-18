#include "sprite.hxx"
Sprite::Sprite(double x, double y, TextureRect * texrec) {
    this->texrec = texrec;
    this->destination.x = x;
    this->destination.y = y;
    SDL_Rect * src = texrec->get_source();
    this->destination.w = src->w;
    this->destination.h = src->h;
}

void Sprite::draw(SDL_Renderer * renderer) {
    this->texrec->draw_to(renderer, &this->destination);
}

void Sprite::step(double dt) {
    
}
