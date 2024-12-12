#include "FPS_counter.hxx"
#include <stdexcept>
#include "../../cuistax/cui_debug.hxx"
static char fps_buff[MAX_DIGITS];

FPSCounter::FPSCounter(
        int x, int y, size_t n_digits,
        FontResource * font, double refresh
    ) : 
        n_digits(n_digits), font(font), refresh(refresh),
        fps_text(font, "FPS: ", x, y), 
        fps_number(font, fps_buff, x + fps_text.get_width(), y)
    {
    if (n_digits > MAX_DIGITS) 
        throw std::invalid_argument("exceeding max digits");
    //build format in the form of %0<x>i
    int r;
    r = snprintf(format_buff, MAX_FMT_BUF_SIZE, "%%0%ldi", n_digits);
    if (r < 0 || r >= MAX_FMT_BUF_SIZE) {
        CUISTAX_ERR("Error while setting up format string");
    }
    r = snprintf(fps_buff, MAX_DIGITS, format_buff, 0);
    if (r < 0 || r >= MAX_DIGITS) {
        CUISTAX_ERR("Error while setting up fps string");
    }


}


void FPSCounter::step(double dt) {
    counter += dt;
    if (counter >= refresh) {
        counter = 0.0;
        frame_count = 0; 
        sprintf(fps_buff, format_buff, (int)(1.0/dt));
        fps_number.set_string(fps_buff);
    }
}

void FPSCounter::draw(SDL_Renderer * renderer) {
    fps_text.draw(renderer);
    fps_number.draw(renderer);
    frame_count++;
}
