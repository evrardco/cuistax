#pragma once
#include "../base/resource.hxx"
#include "texture_resource.hxx"

typedef struct texture_zone {
    SDL_Rect zone;
    SDL_Texture * texture;
} texture_zone_t;

class TextureZoneResource : public Resource {
    public:
        TextureZoneResource(TextureResource * texture_res, int src_x, int src_y, int src_w, int src_h);
        bool is_loaded();
        void free_data();
        void * get_data();
        int get_width();
        int get_height();
        SDL_Rect * get_src_rect();
    protected:
        void load();
        texture_zone_t texture_zone;
        SDL_Rect src_rect;
        TextureResource * texture_res;
};