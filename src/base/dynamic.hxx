#pragma once
class Dynamic {
    public:
        virtual void step(double) = 0;
        virtual double get_vx();
        virtual double get_vy();
        virtual void set_vx(double);
        virtual void set_vy(double);
        virtual ~Dynamic() {};

    protected:
        double vx;
        double vy;
    private:
};