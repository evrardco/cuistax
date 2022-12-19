
#include "texture_zone_resource.hxx"
#include <stdexcept>
TextureZoneResource::TextureZoneResource(TextureResource * texture_res, int src_x, int src_y, int src_w, int src_h) {
    this->texture_res = texture_res;
    this->texture_zone.zone.x = src_x;
    this->texture_zone.zone.y = src_y;
    this->texture_zone.zone.w = src_w;
    this->texture_zone.zone.h = src_h;
    if (texture_res->is_loaded()) {
        this->loaded = true;
        this->texture_zone.texture = (SDL_Texture *)texture_res->get_data();
    } else {
        throw std::invalid_argument("cannot instantiate TextureZoneResource using unloaded TextureResource");
        this->texture_zone.texture = NULL;
    }
}   

void * TextureZoneResource::get_data() {
    return this->texture_res->get_data();
}

bool TextureZoneResource::is_loaded() {
    return this->texture_res->is_loaded();
}

void TextureZoneResource::free_data() {
    ;
}

void TextureZoneResource::load() {
    ;
}

SDL_Rect * TextureZoneResource::get_src_rect() {
    return &this->src_rect;
}

int TextureZoneResource::get_width() {
    return this->texture_res->get_width();
}

int TextureZoneResource::get_height() {
    return this->texture_res->get_height();
}

