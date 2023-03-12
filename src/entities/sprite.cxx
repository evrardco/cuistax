#include "sprite.hxx"
Sprite::Sprite(double x, double y, TextureZoneResource * texrec) {
    this->texture_zone = texrec;
    this->destination.x = x;
    this->destination.y = y;
    this->destination.w = texture_zone->get_width();
    this->destination.h = texture_zone->get_height();
    this->x = x;
    this->y = x;
    this->vx = 0;
    this->vy = 0;
}
void Sprite::set_x(double x) {
    this->destination.x = x;
    this->x = x;
}
void Sprite::set_y(double y) {
    this->destination.y = y;
    this->y = y;
}
void Sprite::draw(SDL_Renderer * renderer) {
    this->texture_zone->draw_to(renderer, &this->destination);
}

void Sprite::step(double dt) {
    
}
