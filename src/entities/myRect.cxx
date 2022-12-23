#include "myRect.hxx"
int MyRect::get_width() {
    return this->rect.w;
}
int MyRect::get_height() {
    return this->rect.h;
}
void MyRect::set_width(int w) {
    this->rect.w = w;
}
void MyRect::set_height(int h) {
    this->rect.h = h;
}
void MyRect::draw(SDL_Renderer * renderer) {
    this->rect.x = (int) this->x;
    this->rect.y = (int) this->y;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &(this->rect));
}
void MyRect::step(double dt) {
    this->x += this->vx * dt;
    this->y += this->vy * dt;
}

MyRect::MyRect(double x, double y, int w, int h) {
    this->x = x;
    this->y = y;
    this->rect.w = w;
    this->rect.h = h;
    this->vy = 0;
    this->vx = 0;
}