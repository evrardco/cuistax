#include "FPS_counter.hxx"
#include <stdexcept>
#include "../../cuistax/cui_debug.hxx"

static char fps_buff[MAX_DIGITS];
FPSCounter::FPSCounter(int x, int y, size_t n_digits, FontResource * font, double max_period) {
    if (n_digits > MAX_DIGITS) 
        throw std::invalid_argument("exceeding max digits");

    this->max_period = max_period;
    this->n_digits = n_digits;
    this->x = x;
    this->y = y;
    this->font = font;
    //build format in the form of %0<x>i
    sprintf(format_buff, "%%0%ldi", n_digits);
    sprintf(fps_buff, format_buff, 0);

    this->fps_text = new StringImage(font, "FPS: ", x, y);
    this->fps_number = new StringImage(font, fps_buff, x + fps_text->get_width(), y);

}

FPSCounter::~FPSCounter() {
    CUISTAX_DEBUG("Calling FPSCounter destructor");
    delete fps_text;
    delete fps_number;
}
void FPSCounter::step(double dt) {
    counter += dt;
    if (counter == max_period) {
        counter = 0.0;
        frame_count = 0;
    } else {
        sprintf(fps_buff, format_buff, (int)(frame_count/counter));
        // fps_number->set_string(fps_buff);
        // actually, below is faster, for god only knows what awful reason.
        // I can't believe I spent so much time writing optimized string image routines...
        delete fps_number;
        fps_number = new StringImage(font, fps_buff, x + fps_text->get_width(), y);
        
    }
}

void FPSCounter::draw(SDL_Renderer * renderer) {
    fps_text->draw(renderer);
    fps_number->draw(renderer);
    frame_count++;
}
