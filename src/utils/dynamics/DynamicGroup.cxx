#include "DynamicGroup.hxx"
void DynamicGroup::step (double dt) {
    for (auto d = this->begin(); d != this->end(); d++) {
        (*d)->step(dt);
    }
}
DynamicGroup::~DynamicGroup() {
    for (auto d = this->begin(); d != this->end(); d++) {
        delete *d;
    }
}