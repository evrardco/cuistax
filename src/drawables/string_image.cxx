#include "string_image.hxx"
#include <string>
#include <vector>
#include "../resource/font_resource.hxx"
using namespace std;


StringImage::StringImage(FontResource * font, string text, int x, int y) {
    this->x = x;
    this->y = y;
    this->text = text;
    this->font = font;
    int n_lines = 0;
    int n_cols = text.size();
    int cell_size = font->get_cell_size();
    for (int i = 0; i < text.size(); i++) {
        if (text.at(i) == '\n') {
            n_lines += 1;
            n_cols = 0;
            continue;
        }
        this->char_images.push_back(
            Image(
                this->font->get_char(text.at(i)),
                x + n_cols * cell_size, y + n_lines * cell_size  
            )
        );
        n_cols += 1;
    }
}
void StringImage::draw(SDL_Renderer * renderer) {
    for (auto &img : this->char_images) {
        img.draw(renderer);
    }
}
void StringImage::set_x(int x) {
    int delta = x - this->x;
    this->x = x;
    for (int i = 0; i < this->text.size(); i++) {
        Image img = this->char_images.at(i);
        img.set_x(img.get_x() + delta);
    }
}

void StringImage::set_y(int y) {
    int delta = y - this->y;
    this->y = y;
    for (int i = 0; i < this->text.size(); i++) {
        Image img = this->char_images.at(i);
        img.set_y(img.get_y() + delta);
    }
}

void StringImage::set_char(int idx, char c) {
    this->char_images.at(x).set_texture_zone(this->font->get_char(c));
}

