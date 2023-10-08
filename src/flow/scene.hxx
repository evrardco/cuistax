#pragma once
#include "../base/entity.hxx"
#include "../entities/actor.hxx"
#include "../utils/drawables/DrawableGroup.hxx"
#include "../utils/dynamics/DynamicGroup.hxx"
#include <set>

class Actor; //Forward declaration to avoid circular include problems   
class Scene {
    public:
        void add_actor(Actor * to_add);
        void remove_actor(Actor * to_remove);
        void step(double dt);
        void draw(SDL_Renderer * renderer);
    protected:
        std::set<Actor *> actors;
    private:
        
};