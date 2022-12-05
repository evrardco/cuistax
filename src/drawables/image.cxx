#include "image.hxx"
#include <SDL2/SDL.h>
Image::Image(TextureZoneResource * texture_zone, double x, double y) {
    this->texture_zone = texture_zone;
    this->x = x;
    this->y = y;
    this->rect.x = (int)x;
    this->rect.y = (int)y;
    this->rect.w = texture->get_width();
    this->rect.h = texture->get_height();
}

void Image::set_x(double x) {
    this->x = x;
    this->rect.x = (int)x;
}

void Image::set_y(double y) {
    this->y = y;
    this->rect.y = (int)y;
}

int Image::get_width() {
    return this->rect.w;
}

int Image::get_height() {
    return this->rect.y;
}
void Image::draw(SDL_Renderer * renderer) {
    SDL_RenderCopy(
        renderer, ((SDL_Texture * )this->texture_zone->get_data()),
        this->texture_zone->get_src_rect, this->dest_rect
    );
}
