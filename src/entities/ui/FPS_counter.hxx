#include "../../drawables/string_image.hxx"
#include "../../base/dynamic.hxx"
class FPSCounter : public Dynamic, public Drawable {
    public:
        FPSCounter(int x, int y, const char * format);
        ~FPSCounter();
        void step(double dt) override;
        void draw(SDL_Renderer * renderer) override;
    protected:
        double counter = 0.0;
        uint32_t frame_count = 0;
        StringImage * fps_text = NULL;
    private:
};
