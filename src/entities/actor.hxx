#pragma once
#include "../base/entity.hxx"
#include "../flow/scene.hxx"
class Scene;
/**
 * @brief Actors are entities meant to be part of one and only one scene
 */
class Actor : public Entity {
    public:
        void set_scene(Scene *);
    protected:
        Scene * scene;
        bool killed = false;
    private:
};