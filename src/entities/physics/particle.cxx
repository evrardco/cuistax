#include "particle.hxx"
void Particle::set_max_vel(double max_vel) {
    this->max_vel = max_vel;
}
double Particle::get_vel() {
    return sqrtf64(powf64(this->vx, 2) + powf64(this->vy, 2));
}
double Particle::get_mass() {
    return this->mass;
}
double Particle::dist(Particle other) {
    return sqrtf64(
        powf64(this->x - other.get_x(), 2) +
        powf64(this->y - other.get_y(), 2)
    );
}
void Particle::apply_gravity (Particle other) {
    double r = this->dist(other);
    double accel_mul = other.get_mass() * UNIVERSAL_CONSTANT / powf64(r, 2);
    printf("mul=%f", accel_mul);
    this->vx += (other.get_x() - this->x) * accel_mul; 
    this->vy += (other.get_y() - this->y) * accel_mul; 
}
void Particle::step(double dt) {
    for (int i = this->id; i < this->universe.size(); i++) {
        this->apply_gravity(*(this->universe.at(i)));
    }
    this->green = (int)(255 * (this->get_vel()/this->max_vel));
    Box::step(dt);
}
Particle::Particle(double x, double y, int w, int h, std::vector<Particle *> universe, int id) : Box(x, y, w, h) {
    this->green = 0;
    this->mass = (double)rand() / RAND_MAX;
    printf("mass=%f\n", this->mass);
    // this->vx = (double)rand() / RAND_MAX;
    // this->vy = (double)rand() / RAND_MAX;   
    this->id = id;
    this->universe = universe;
    this->max_vel = this->get_vel(); 
}
void Particle::draw(SDL_Renderer * renderer) {
    this->rect.x = (int) this->x;
    this->rect.y = (int) this->y;
    SDL_SetRenderDrawColor(renderer, 255, green, 0, 255);
    SDL_RenderFillRect(renderer, &(this->rect));
}