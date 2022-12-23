#pragma once
#include "../base/resource.hxx"
#include <cstring>
#include <SDL2/SDL.h>
class TextureResource : public Resource {
    public:
        TextureResource(const char * path, SDL_Renderer * renderer);
        ~TextureResource();
        void * get_data() override;
        void free_data() override;
        int get_width();
        int get_height();
        void load() override;
    protected:
        SDL_Surface * surface;
        SDL_Texture * texture;
        SDL_Renderer * renderer;
    private:
};

