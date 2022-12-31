#include "../../drawables/string_image.hxx"
#include "../../base/entity.hxx"
#include "../../resource/font_resource.hxx"
#define MAX_DIGITS 32
class FPSCounter : public Entity{
    public:
        FPSCounter(int x, int y, size_t n_digits, FontResource * font, double max_period);
        ~FPSCounter();
        void step(double dt) override;
        void draw(SDL_Renderer * renderer) override;
    protected:
        double counter = 0.0;
        uint32_t frame_count = 0;
        size_t n_digits;
        double max_period = 1.0;
        StringImage * fps_text;
        StringImage * fps_number;
        char format_buff[5];
        FontResource * font;
    private:
};
