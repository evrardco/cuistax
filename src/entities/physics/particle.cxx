#include "particle.hxx"
void Particle::set_max_vel(double max_vel) {
    this->max_vel = max_vel;
}
double Particle::get_vel() {
    return sqrt(pow(this->vx, 2) + pow(this->vy, 2));
}
double Particle::get_mass() {
    return this->mass;
}
double Particle::dist(Particle other) {

    return sqrt(
        pow(this->x - other.get_x(), 2) +
        pow(this->y - other.get_y(), 2)
    );
}
void Particle::apply_gravity (Particle other, double dt) {
    double r = this->dist(other);
    double accel_mul = other.get_mass() * UNIVERSAL_CONSTANT / (pow(r, 2) + 1);
    accel_mul += pow(other.get_mass(), r);
    
    double dx = other.get_x() - this->x;
    double dy = other.get_y() - this->y;
    this->vx += dx * accel_mul * dt; 
    this->vy += dy * accel_mul * dt; 
    other.set_vx(other.get_vx() - dx * accel_mul * dt);
    other.set_vy(other.get_vy() - dy * accel_mul * dt);    
}
void Particle::step(double dt) {
    for (int i = this->id; i < (this->universe)->size(); i++) {
        this->apply_gravity(*(this->universe->at(i)), dt);
    }
    this->green = (int)(255 * (this->get_vel()/this->max_vel));
    Box::step(dt);
}
Particle::Particle(double x, double y, int w, int h, std::vector<Particle *> *universe , int id) : Box(x, y, w, h) {
    this->green = 0;
    this->mass = ((double)rand() / RAND_MAX);
    //printf("mass=%f\n", this->mass);
    //this->vx = (double)rand() / RAND_MAX;
    //this->vy = (double)rand() / RAND_MAX;   
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