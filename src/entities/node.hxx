#include "../base/entity.hxx"
#include "../base/drawable.hxx"
#include "SDL2/SDL.h"
#include <vector>
class Group : public std::vector<Entity *>, public Entity {
    public:
        Group(bool);
        void step(double);
        void draw(SDL_Renderer *);
        void set_active(bool);
        bool is_active();
    protected:
        bool active;
    private:
};
