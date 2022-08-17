#pragma once
#include <unordered_map>
#include "../base/resource.hxx"
class ResourceManager {  
    public:
        void add(char * name, Resource * resource);
        void load(char * name);
        void add_and_load(char * name, Resource * resource);
        void remove(char * name);
        void * get_data(char * name);
        Resource * get(char * name);
        int get_size();
        ~ResourceManager();
    protected:

    private:
        std::unordered_map<char *, Resource *> cache;
};
