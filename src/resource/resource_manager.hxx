#pragma once
#include <unordered_map>
#include "../base/resource.hxx"
#include <utility>

class ResourceManager {  
    public:
        void add(const char * name, Resource * resource);
        void load(const char * name);
        void add_and_load(const char * name, Resource * resource);
        void remove(const char * name);
        void * get_data(const char * name);
        Resource * get(const char * name);
        int get_size();
        ~ResourceManager();
    protected:

    private:
        std::unordered_map<const char *, Resource *> cache;
};
