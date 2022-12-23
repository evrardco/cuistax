#pragma once
#include "../base/entity.hxx"
#include "../resource/texture_zone_resource.hxx"

class Sprite : public Entity {
    public:
        Sprite(double x, double y, TextureZoneResource * texrec);
        void draw(SDL_Renderer * renderer) override;
        void step(double dt) override;
        void set_x(double x) override;
        void set_y(double y) override;
    protected:
        SDL_Rect destination;
        TextureZoneResource * texture_zone;
    private:
};



