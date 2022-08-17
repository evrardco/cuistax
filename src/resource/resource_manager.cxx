#include "resource_manager.hxx"
ResourceManager::~ResourceManager() {
    std::unordered_map<char *, Resource *>::iterator it;
    for(it=this->cache.begin(); it != this->cache.end(); it++) {
        delete it->second;
    }
    
}
void ResourceManager::add(char * name, Resource * resource) {
    this->cache[name] = resource;
}

void ResourceManager::load(char * name) {
    this->cache[name]->load();
}

void ResourceManager::add_and_load(char * name, Resource * resource) {
    resource->load();
    this->cache[name] = resource;
}

void ResourceManager::remove(char * name) {
    this->cache.erase(name);
}

Resource * ResourceManager::get(char * name) {
    return this->cache[name];
}

int ResourceManager::get_size() {
    return this->cache.size();
}

void * ResourceManager::get_data(char * name) {
    return this->cache[name]->get_data();
}