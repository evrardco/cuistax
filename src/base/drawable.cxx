#include "drawable.hxx"
double Drawable::get_x() {
    return this->x;
}
double Drawable::get_y() {
    return this->y;
}
void Drawable::set_x(double x) {
    this->x = x;
}
void Drawable::set_y(double y) {
    this->y = y;
}
SDL_Renderer * Drawable::get_renderer() {
    return this->renderer;
}
