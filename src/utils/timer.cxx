#include "timer.hxx"
Timer::Timer(double interval, std::function<void(void)> callback, timer_type type = ONCE, bool activated = true) {
    this->callback = callback;
    this->interval = interval;
    this->time_left = interval;
    this->activated = activated;
    this->type = type;
    this->vx = 0;
    this->vy = 0;
}

void Timer::step(double dt) {
    if(!this->activated) return;
    this->time_left -= dt;
    if (this->time_left <= 0) {
        this->activated = this->type == REPEAT;
        this->time_left = this->interval;
        this->callback();
    }
    
}