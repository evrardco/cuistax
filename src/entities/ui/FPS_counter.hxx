#include "../../drawables/string_image.hxx"
#include "../../base/entity.hxx"
#include "../../resource/font_resource.hxx"
#include "../actor.hxx"
#define MAX_DIGITS 32
#define MAX_FMT_BUF_SIZE 16 
class FPSCounter : public Actor {
    public:
        FPSCounter(int x, int y, size_t n_digits, FontResource * font, double max_period);
        void step(double dt) override;
        void draw(SDL_Renderer * renderer) override;
    protected:
        double refresh; 
        double counter = 0.0;
        uint32_t frame_count = 0;
        size_t n_digits;
        double max_period = 1.0;
        StringImage fps_text;
        StringImage fps_number;
        char format_buff[MAX_FMT_BUF_SIZE];
        FontResource * font;
    private:
};
