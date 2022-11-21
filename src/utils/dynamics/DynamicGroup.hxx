#pragma once
#include <vector>
#include "../../base/dynamic.hxx"
class DynamicGroup : public std::vector<Dynamic *>, public Dynamic {
    public:
    void step(double dt);
    ~DynamicGroup();
    private:
};