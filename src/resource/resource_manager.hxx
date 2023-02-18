#pragma once
#include <unordered_map>
#include "../base/resource.hxx"
#include <utility>
typedef enum resource_type {
    TEXTURE_RESOURCE = 0,
    FONT_RESOURCE,
    TEXTURE_ZONE_RESOURCE
} resource_type;

class ResourceManager {  
    public:
        void add(const char * name, Resource * resource, resource_type type);
        void load(const char * name);
        void add_and_load(const char * name, Resource * resource, resource_type type);
        void remove(const char * name);
        void * get_data(const char * name);
        Resource * get(const char * name);
        int get_size();
        ~ResourceManager();
    protected:

    private:
        std::unordered_map<const char *, std::pair<Resource *, resource_type>> cache;
};
