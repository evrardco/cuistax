#include "image.hxx"
#include <SDL2/SDL.h>
Image::Image(TextureZoneResource * texture_zone, double x, double y) {
    this->texture_zone = texture_zone;
    this->x = x;
    this->y = y;
    this->dest_rect.x = (int)x;
    this->dest_rect.y = (int)y;
    this->dest_rect.w = texture_zone->get_width();
    this->dest_rect.h = texture_zone->get_height();
}

void Image::set_x(double x) {
    this->x = x;
    this->dest_rect.x = (int)x;
}

void Image::set_y(double y) {
    this->y = y;
    this->dest_rect.y = (int)y;
}

int Image::get_width() {
    return this->dest_rect.w;
}

int Image::get_height() {
    return this->dest_rect.y;
}
void Image::draw(SDL_Renderer * renderer) {
    SDL_RenderCopy(
        renderer, ((SDL_Texture * )this->texture_zone->get_data()),
        this->texture_zone->get_src_rect(), &this->dest_rect
    );
}

void Image::set_texture_zone(TextureZoneResource * tex_zone) {
    this->texture_zone = tex_zone;
}
TextureZoneResource * Image::get_texture_zone() {
    return this->texture_zone;
}