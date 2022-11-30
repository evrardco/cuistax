#include "texture_resource.hxx"
class TextureZoneResource : public Resource {
    public:
        TextureZoneResource(TextureResource * texture_res, int src_x, int src_y, int src_w, int src_h);
        bool is_loaded();
        void free_data();
        void * get_data();
        SDL_Rect * get_src_rect();
    protected:
        void load();
        SDL_Rect src_rect;
        TextureResource * texture_res;
};