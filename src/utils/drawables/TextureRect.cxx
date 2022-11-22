#include "TextureRect.hxx"
TextureRect::TextureRect(SDL_Texture * texture, int x, int y, int w, int h) {
    this->texture = texture;
    this->source.x = x;
    this->source.y = y;
    this->source.w = w;
    this->source.h = h;
}

void TextureRect::draw_to(SDL_Renderer * renderer, SDL_Rect * dest) {
    SDL_RenderCopy(renderer, this->texture, &this->source, dest);
}

SDL_Rect * TextureRect::get_source() {
    return &this->source;
}
double TextureRect::get_texture_x() {
    return this->source.x;
}
double TextureRect::get_texture_y() {
    return this->source.y;
}
double TextureRect::get_texture_width(){
    return this->source.w;
}
double TextureRect::get_texture_height(){
    return this->source.h;
}

void TextureRect::set_texture_x(double x) {
    this->source.x = x;
}
void TextureRect::set_texture_y(double y) {
    this->source.y = y;
}
void TextureRect::set_texture_width(double w){
    this->source.w = w;
}
void TextureRect::set_texture_height(double h) {
    this->source.h = h;
}