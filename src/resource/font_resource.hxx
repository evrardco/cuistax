#pragma once
#include "../base/resource.hxx"
#include "../resource/texture_resource.hxx"
#include "../utils/graphics/TextureRect.hxx"
#include "../utils/DrawableGroup.hxx"
#include <SDL2/SDL.h>
#include <ctype.h>
#include <vector>
#include <string>
class FontResource : public Resource {
    public:
        FontResource(SDL_Renderer * renderer, TextureResource * texture, uint8_t char_size, uint8_t cell_size, uint8_t inter_char_size);
        void load();
        void * get_data();
        void free_data();
        DrawableGroup * string_to_drawables(std::string str, int x, int y);
    protected:
        uint8_t char_size;
        uint8_t cell_size;
        uint8_t inter_char_size;
        TextureResource * font_texture;
        SDL_Renderer * renderer;
        std::vector<TextureRect> tex_rec_vec;
        
    private:
};