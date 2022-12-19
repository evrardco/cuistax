#pragma once
#include "../base/drawable.hxx"
#include "../resource/texture_resource.hxx"
#include "../resource/texture_zone_resource.hxx"
class Image : public Drawable {
    public:
        Image(TextureZoneResource * texture_zone, double x, double y);
        void draw(SDL_Renderer * renderer);
        int get_width();
        int get_height();
        void set_x(double x);
        void set_y(double y);
        void set_texture_zone(TextureZoneResource * tex_zone);
        TextureZoneResource * get_texture_zone();
    
    protected:    
        TextureZoneResource * texture_zone; 
        SDL_Rect dest_rect;
};
