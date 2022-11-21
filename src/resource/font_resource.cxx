#pragma once
#include "font_resource.hxx"
#include "../base/resource.hxx"
#include "../entities/sprite.hxx"
#include "../resource/texture_resource.hxx"
#include "../utils/drawables/TextureRect.hxx"
#include "../utils/drawables/DrawableGroup.hxx"
#include <SDL2/SDL.h>
#include <ctype.h>
#include <vector>
#include <string>

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
/**
 * @brief Allocates a DrawableGroup
 * 
 * @param str 
 * @param x 
 * @param y 
 * @return DrawableGroup * 
 */
DrawableGroup * FontResource::string_to_drawables(std::string str, int x, int y) {
    int n = str.size();
    const char * cstr = str.c_str();
    DrawableGroup * ret = new DrawableGroup();
    for (int i = 0; i < n; i++) {
        ret->push_back(
            new Sprite(
                x + i * this->cell_size, y,
                &((std::vector<TextureRect> *)(this->get_data()))->at((int)cstr[i])
            )
        );
    }
    return ret;
}