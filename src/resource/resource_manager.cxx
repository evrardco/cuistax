#include "resource_manager.hxx"
#include "../utils/debug.hxx"
#include "texture_resource.hxx"
#include "texture_zone_resource.hxx"
#include "font_resource.hxx"
#include <utility>
#include <stdexcept>

ResourceManager::~ResourceManager() {
    for (auto res : cache) {
        delete res.first;
    }
}
void ResourceManager::add(const char * name, Resource * resource, resource_type type) {
        cache[name] = std::make_pair(resource, type);
}
void ResourceManager::load(const char * name) {
    cache[name].first->load();
}

void ResourceManager::add_and_load(const char * name, Resource * resource, resource_type type) {
    resource->load();
    cache[name] = std::make_pair(resource, type);
}

void ResourceManager::remove(const char * name) {
    cache.erase(name);
}

Resource * ResourceManager::get(const char * name) {
    return cache[name].first;
}

int ResourceManager::get_size() {
    return cache.size();
}

void * ResourceManager::get_data(const char * name) {
    return cache[name].first->get_data();
}