#include "texture_resource.hxx"
#include <cstring>
#include <stdexcept>
#include "../utils/formatting.hxx"
#include "../cuistax/cui_debug.hxx"
TextureResource::TextureResource(const char * path, SDL_Renderer * renderer) {
    size_t sz = strlen(path) + 1;
    this->path = new char[sz];
    strcpy(this->path, path);
    this->loaded = false;
    this->renderer = renderer;
}

void * TextureResource::get_data() {
    return this->texture;
}

int TextureResource::get_width() {
    return this->surface->w;
}

int TextureResource::get_height() {
    return this->surface->h;
}


void TextureResource::load() {
    this->surface = SDL_LoadBMP(this->path);
    if (this->surface == NULL) {
        std::string out;
        str_fmt(out, "Error loading bmp: %s\n", this->path);
        throw std::invalid_argument(out);
    }
    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
    this->loaded = true;
}

void TextureResource::free_data() {
    CUISTAX_LOG("Freeing SDL_TEXTURE from texture resource");
    SDL_FreeSurface(this->surface);
    SDL_DestroyTexture(this->texture);
}

TextureResource::~TextureResource() {
    CUISTAX_LOG("Calling texture font destructor");
    this->free_data();
    delete[] this->path;
}


