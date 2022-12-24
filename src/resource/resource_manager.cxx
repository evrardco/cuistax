#include "resource_manager.hxx"
#include "../utils/debug.hxx"
#include "texture_resource.hxx"
#include "texture_zone_resource.hxx"
#include "font_resource.hxx"
#include <utility>
#include <stdexcept>

void destroy_resource(Resource * resource, resource_type type) {
    switch(type) {
        case TEXTURE_RESOURCE : {
            delete (TextureResource *) resource;
            break;
        }
        case TEXTURE_ZONE_RESOURCE : {
            delete (TextureZoneResource *) resource;
            break;
        }
        case FONT_RESOURCE : {
            delete (FontResource *) resource;
            break;
        }
        default:
            throw std::invalid_argument("could not find corresponding destructor");
    }
}

ResourceManager::~ResourceManager() {
    std::unordered_map<const char *, std::pair<Resource *, int>>::iterator it;
    for(it=this->cache.begin(); it != this->cache.end(); it++) {
        YAE_LOG("Calling destructor of %s, with address %p\n", it->first, it->second);
        destroy_resource(it->second.first, (resource_type)it->second.second);
    }
    
}
void ResourceManager::add(const char * name, Resource * resource, resource_type type) {
    this->cache[name] = std::make_pair(resource, type);

}
void ResourceManager::load(const char * name) {
    this->cache[name].first->load();
}

void ResourceManager::add_and_load(const char * name, Resource * resource, resource_type type) {
    resource->load();
    this->cache[name] = std::make_pair(resource, type);
}

void ResourceManager::remove(const char * name) {
    this->cache.erase(name);
}

Resource * ResourceManager::get(const char * name) {
    return this->cache[name].first;
}

int ResourceManager::get_size() {
    return this->cache.size();
}

void * ResourceManager::get_data(const char * name) {
    return this->cache[name].first->get_data();
}