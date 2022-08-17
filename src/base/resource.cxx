#include "resource.hxx"

void * Resource::get_data() {
    return this->data;
}

bool Resource::is_loaded() {
    return this->loaded;
}