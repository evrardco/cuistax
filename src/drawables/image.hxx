#include "../base/drawable.hxx"
#include "../resource/texture_resource.hxx"
#include "../resource/texture_zone_resource.hxx"
class Image : public Drawable {
    public: 
        Image(TextureZoneResource * texture_zone, double x, double y);
        void draw(SDL_Renderer * renderer);
        int get_width();
        int get_height();
    
    protected:    
        TextureZoneResource * texture_zone; 
        SDL_Rect dest_rect;
};
