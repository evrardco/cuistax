#pragma once
class Resource {
    public:
        virtual void load() = 0;
        virtual void * get_data();
        virtual bool is_loaded();
        virtual void free_data() = 0;

    protected:
        double loaded;
        void * data;
        char * path;
    private:
};