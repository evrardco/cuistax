#include "texture_resource.hxx"
TextureResource::TextureResource(char * path, SDL_Renderer * renderer) {
    size_t sz = strlen(path) + 1;
    this->path = new char[sz];
    memcpy(this->path, path, sz);
    this->loaded = false;
    this->renderer = renderer;
}

void * TextureResource::get_data() {
    return this->texture;
}
void TextureResource::load() {
    this->surface = SDL_LoadBMP(this->path);
    if (this->surface == NULL) {
        printf("Error loading bmp: %s\n", this->path);
    }
    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
    this->loaded = true;
}

TextureResource::~TextureResource() {
    SDL_FreeSurface(this->surface);
    SDL_DestroyTexture(this->texture);
    delete this->path;
}

