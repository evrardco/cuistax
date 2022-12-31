#include "resource_manager.hxx"
#include "../utils/debug.hxx"
#include "texture_resource.hxx"
#include "texture_zone_resource.hxx"
#include "font_resource.hxx"
#include <utility>
#include <stdexcept>

ResourceManager::~ResourceManager() {
    for (auto res : cache) {
        delete res.second;
    }
}
void ResourceManager::add(const char * name, Resource * resource) {
    cache[name] = resource;

}
void ResourceManager::load(const char * name) {
    cache[name]->load();
}

void ResourceManager::add_and_load(const char * name, Resource * resource) {
    resource->load();
    cache[name] = resource;
}

void ResourceManager::remove(const char * name) {
    cache.erase(name);
}

Resource * ResourceManager::get(const char * name) {
    return cache[name];
}

int ResourceManager::get_size() {
    return cache.size();
}

void * ResourceManager::get_data(const char * name) {
    return cache[name]->get_data();
}