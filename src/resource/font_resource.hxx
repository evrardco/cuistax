#pragma once
#include "../base/resource.hxx"
#include "../resource/texture_resource.hxx"
#include "../utils/drawables/DrawableGroup.hxx"
#include "../drawables/image.hxx"
#include "../resource/texture_zone_resource.hxx"
#include "../cuistax/cui_engine.hxx"
#include <SDL2/SDL.h>
#include <ctype.h>
#include <vector>
#include <string>
class FontResource : public Resource {
    public:
        FontResource(SDL_Renderer * renderer, TextureResource * texture, uint8_t char_size, uint8_t cell_size, uint8_t inter_char_size);
        FontResource(cui_context_t * ctx, TextureResource * texture, uint8_t char_size, uint8_t cell_size, uint8_t inter_char_size);

        ~FontResource();
        void load() override;
        void * get_data() override;
        void free_data() override;
        TextureZoneResource * get_char_texture_zone(char c);
        int get_min_char();
        int get_max_char();
        int get_char_size();
        int get_cell_size();
        TextureZoneResource * get_char(char c);
    protected:
        int min_char;
        int max_char;
        uint8_t char_size;
        uint8_t cell_size;
        uint8_t inter_char_size;
        TextureResource * font_texture;
        SDL_Renderer * renderer;
        std::vector<TextureZoneResource *> font_texture_zones;
        
    private:
};