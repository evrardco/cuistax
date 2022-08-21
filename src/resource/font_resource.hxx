#pragma once
#include "../base/resource.hxx"
#include "../resource/texture_resource.hxx"
#include "../utils/graphics/TextureRect.hxx"
#include <SDL2/SDL.h>
#include <ctype.h>
#include <vector>
class FontResource : public Resource {
    public:
        FontResource(SDL_Renderer * renderer, TextureResource * texture, uint8_t char_size, uint8_t cell_size, uint8_t inter_char_size);
        void load();
        void * get_data();
        void free_data();
    protected:
        uint8_t char_size;
        uint8_t cell_size;
        uint8_t inter_char_size;
        TextureResource * font_texture;
        SDL_Renderer * renderer;
        std::vector<TextureRect> tex_rec_vec;
        
    private:
};

FontResource::FontResource(SDL_Renderer * renderer, TextureResource * texture, uint8_t char_size, uint8_t cell_size, uint8_t inter_char_size) {
    this->cell_size = cell_size;
    this->char_size = char_size;
    this->font_texture = texture;
    this->renderer = renderer;
}

void FontResource::load() {

    if (loaded) {
        printf("Resource already loaded !\n");
        return;
    }
    if (!font_texture->is_loaded()) {
        printf("Associated texture not loaded !\n");
        return;
    }
    SDL_Texture * tex = (SDL_Texture *)font_texture->get_data();
    size_t num_rows = font_texture->get_height() / cell_size;
    size_t num_cols = font_texture->get_width() / cell_size;
    //TextureRect(SDL_Texture * texture, int x, int y, int w, int h)
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            this->tex_rec_vec.push_back(TextureRect(
                tex,
                j * this->cell_size, i * this->cell_size,
                this->char_size, this->char_size
            )); 
        }
    }

    this->loaded = true;
}

void FontResource::free_data() {
    
}

void * FontResource::get_data() {
    return &this->tex_rec_vec;
}