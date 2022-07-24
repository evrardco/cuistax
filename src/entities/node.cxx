#include "node.hxx"
Group::Group(bool active = true) 
: std::vector<Entity *>() {
    this->active = active;
}

void Group::step(double dt) {
    for(std::size_t i = 0; i < this->size(); i++) {
        (*this)[i]->step(dt);
    }
}

void Group::draw(SDL_Renderer * renderer) {
    for(std::size_t i = 0; i < this->size(); i++) {
        (*this)[i]->draw(renderer);
    }
}

bool Group::is_active() {
    return this->active;
}