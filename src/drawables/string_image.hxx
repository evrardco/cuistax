#include "image.hxx"
#include <string>
#include <vector>
#include "../resource/font_resource.hxx"

class StringImage : public Drawable {
    public:
        StringImage(FontResource * font, std::string, int x, int y);
        ~StringImage();
        void set_x(int x);
        void set_y(int y);
        void draw(SDL_Renderer *) override;
        void set_char(int idx, char c);
    protected:
        FontResource * font;
        std::vector<Image *> char_images;
        std::string text;
    private:
};