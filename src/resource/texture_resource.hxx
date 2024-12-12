#pragma once
#include "../base/resource.hxx"
#include "../cuistax/cui_engine.hxx"
#include <cstring>
#include <SDL2/SDL.h>
class TextureResource : public Resource {
    public:
        TextureResource(const char * path, SDL_Renderer * renderer);
        TextureResource(const char * path, cui_context_t * renderer);

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

