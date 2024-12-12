#include "font_resource.hxx"
#include "../base/resource.hxx"
#include "../entities/sprite.hxx"
#include "../resource/texture_resource.hxx"
#include "../utils/drawables/DrawableGroup.hxx"
#include <SDL2/SDL.h>
#include <ctype.h>
#include <vector>
#include <string>
#include <stdexcept>

FontResource::FontResource(SDL_Renderer * renderer, TextureResource * texture, uint8_t char_size, uint8_t cell_size, uint8_t inter_char_size) {
    this->cell_size = cell_size;
    this->char_size = char_size;
    this->font_texture = texture;
    this->renderer = renderer;
    this->min_char = 0;
    this->max_char = UINT8_MAX;
    this->inter_char_size = inter_char_size;
}

FontResource::FontResource(cui_context_t * ctx, TextureResource * texture, uint8_t char_size, uint8_t cell_size, uint8_t inter_char_size) {
    this->cell_size = cell_size;
    this->char_size = char_size;
    this->font_texture = texture;
    this->renderer = ctx->backend_ctx.ctx_SDL.renderer;
    this->min_char = 0;
    this->max_char = UINT8_MAX;
    this->inter_char_size = inter_char_size;
}


FontResource::~FontResource() {
    for (auto tex_zone : this->font_texture_zones) {
        delete tex_zone;
    }
}

void FontResource::load() {
    if (!this->font_texture->is_loaded()) throw std::invalid_argument("cannot instantiate FontResource with unloaded TextureResource");

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
    this->min_char = 0;
    this->max_char =  num_rows * num_cols;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            this->font_texture_zones.push_back(
                new TextureZoneResource(this->font_texture, j * this->cell_size,
                i * this->cell_size, this->char_size, this->char_size)
            );
        }
    }

    
    this->loaded = true;
    

}

void FontResource::free_data() {
    
}

void * FontResource::get_data() {
    return &this->font_texture_zones;
}

int FontResource::get_min_char() {
    return this->min_char;
}

int FontResource::get_max_char() {
    return this->max_char;
}

TextureZoneResource * FontResource::get_char_texture_zone(char c) {
    int idx = (int)c;
    if (c < min_char || c >= max_char) return NULL;

    return this->font_texture_zones.at(idx);

}

int FontResource::get_char_size() {
    return this->char_size;
}

int FontResource::get_cell_size() {
    return this->cell_size;
}

TextureZoneResource * FontResource::get_char(char c) {
    if (c > max_char || c < min_char) {
        throw std::invalid_argument("could not find char in font");
    }
    return this->font_texture_zones.at(c);
}