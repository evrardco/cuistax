#pragma once
#include "../myRect.hxx"
#include "../../constants.hxx"
class Box : public MyRect {
    public:
        Box(double, double, int, int);
        void worldCollide(double, double);
        bool isCollidingWith(Box other);
        void resolveCollision(Box other);
        void step(double)  override;

    protected:

    private:
};
