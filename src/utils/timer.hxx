#include "../base/dynamic.hxx"
#include <functional>
enum timer_type {ONCE, REPEAT};
class Timer : public Dynamic {
    public: 
        Timer(double, std::function<void(void)>, timer_type, bool);
        void step(double);
    protected:
        std::function<void(void)> callback;
        double interval;
        double time_left;
        bool activated;
        bool type;
    private:
};