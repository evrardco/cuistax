#include "box.hxx"
#include <cmath>
Box::Box(double x, double y, int w, int h) : MyRect(x, y, w, h) {

}
void Box::worldCollide(double old_x, double old_y) {

    if (this->x <= 0 || (this->x + this->rect.w) >= WIDTH) {
        this->x = old_x;
        this->vx *= -1;
    }
    if (this->y <= 0 || (this->y + this->rect.h) >= HEIGHT) {
        this->y = old_y;
        this->vy *= -1;
    }
}

void Box::step(double dt) {
    double old_x = this->x;
    double old_y = this->y;
    MyRect::step(dt);
    this->worldCollide(old_x, old_y);
}