#include "box.hxx"
#include "../node.hxx"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#define UNIVERSAL_CONSTANT 100000
class Particle : public Box {
    public:
        Particle(double, double, int, int, std::vector<Particle *>, int);
        void step(double);
        void draw(SDL_Renderer *);
        void apply_gravity(Particle);
        void set_max_vel(double);
        double get_vel();
        double get_mass();
        double dist(Particle);
    protected:
        std::vector<Particle *> universe;
        uint8_t green;
        double mass;
        double max_vel;
        int id;
    private:
};