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
        void set_string(std::string str);
        void strip(size_t n_chars);
        size_t size();
    protected:
        FontResource * font;
        std::vector<Image *> char_images;
        std::string text;
        std::vector<size_t> line_lengths;
        void add_char(char c);
        int n_cols = 0;
        int n_lines = 0;
        int cell_size = 0;
    private:
};