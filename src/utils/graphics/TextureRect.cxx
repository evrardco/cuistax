#include "TextureRect.hxx"
TextureRect::TextureRect(SDL_Texture * texture, int x, int y, int w, int h) {
    this->texture = texture;
    this->source.x = x;
    this->source.y = y;
    this->source.w = w;
    this->source.h = h;
}

void TextureRect::draw_to(SDL_Renderer * renderer, SDL_Rect * dest) {
    SDL_RenderCopy(renderer, this->texture, &this->source, dest);
}

SDL_Rect * TextureRect::get_source() {
    return &this->source;
}