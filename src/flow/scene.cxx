#include "scene.hxx"
#include <iterator>


void Scene::add_actor(Actor * to_add) {
    this->actors.push_back(to_add);
    to_add->set_scene(this);
}
void Scene::remove_actor(Actor * to_remove) {
    int i = 0;
    for (auto actor_ptr : this->actors) {
        if (actor_ptr == to_remove) {
            actors.erase(actors.begin() + i);
            break;
        }
        i++;
    }
    to_remove->set_scene(nullptr);
}

void Scene::step(double dt) {
    for (auto actor_ptr : this->actors) {
        actor_ptr->step(dt);
    }
}

void Scene::draw(SDL_Renderer * renderer) {
    for (auto actor_ptr : this->actors) {
        actor_ptr->draw(renderer);
    }
}

