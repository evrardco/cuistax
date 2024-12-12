#pragma once
#include "../entities/actor.hxx"
#include <set>
#include <vector>

class Actor; //Forward declaration to avoid circular include problems   
class Scene {
    public:
        void add_actor(Actor * to_add);
        void remove_actor(Actor * to_remove);
        void step(double dt);
        void draw(SDL_Renderer * renderer);
    protected:
        std::vector<Actor *> actors;
    private:
        
};