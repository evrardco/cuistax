#pragma once
#include <vector>
#include "../dynamics/DynamicGroup.hxx"
#include "../drawables/DrawableGroup.hxx"

class EntityGroup :  public DrawableGroup, public DynamicGroup {
    public:
    ~EntityGroup() : ~DrawableGroup;
    private:
};