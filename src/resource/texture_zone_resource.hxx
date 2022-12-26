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
        bool is_loaded() override;
        void free_data() override;
        void * get_data() override;
        int get_width();
        int get_height();
        void draw_to(SDL_Renderer * renderer, SDL_Rect * rect);
        SDL_Rect * get_src_rect();
    protected:
        void load() override;
        texture_zone_t texture_zone = {
            .zone = {                               
                        .x = 0,
                        .y = 0,
                        .w = 0,
                        .h = 0                          
                    },
            .texture = nullptr 
        };
        TextureResource * texture_res;
};