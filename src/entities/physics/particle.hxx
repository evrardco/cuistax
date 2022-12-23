#include "box.hxx"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#define UNIVERSAL_CONSTANT 10
#define AGRREGATE_FACTOR 0.001
class Particle : public Box {
    public:
        Particle(double, double, int, int, std::vector<Particle *> *, int);
        void step(double) override;
        void draw(SDL_Renderer *) override;
        void apply_gravity(Particle, double);
        void set_max_vel(double);
        double get_vel();
        double get_mass();
        double dist(Particle);
    protected:
        std::vector<Particle *> * universe;
        uint8_t green;
        double mass;
        double max_vel;
        int id;
    private:
};