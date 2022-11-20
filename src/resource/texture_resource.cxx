#include "texture_resource.hxx"
#include <cstring>
TextureResource::TextureResource(const char * path, SDL_Renderer * renderer) {
    size_t sz = strlen(path) + 1;
    this->path = new char[sz];
    strncpy(this->path, path, sz);
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
        printf("Error loading bmp: %s\n", this->path);
    }
    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
    this->loaded = true;
}

void TextureResource::free_data() {
    SDL_FreeSurface(this->surface);
    SDL_DestroyTexture(this->texture);
}

TextureResource::~TextureResource() {
    this->free_data();
    delete this->path;
}


