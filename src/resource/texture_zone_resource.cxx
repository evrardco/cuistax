
#include "texture_zone_resource.hxx"
TextureZoneResource::TextureZoneResource(TextureResource * texture_res, int src_x, int src_y, int src_w, int src_h) {
    this->texture_res = texture_res;
    this->src_rect.x = src_x;
    this->src_rect.y = src_y;
    this->src_rect.w = src_w;
    this->src_rect.h = src_h;
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

SDL_Rect * TextureZoneResource::get_src_rect() {
    return &this->src_rect;
}


