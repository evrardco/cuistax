#include "scene.hxx"

void Scene::add_actor(Actor * to_add) {
    this->actors.emplace(to_add);
}
void Scene::remove_actor(Actor * to_remove) {
    this->actors.erase(to_remove);
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