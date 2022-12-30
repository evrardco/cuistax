#include "string_image.hxx"
#include <string>
#include <vector>
#include "../resource/font_resource.hxx"
#include "../utils/debug.hxx"
using namespace std;


StringImage::StringImage(FontResource * font, string text, int x, int y) {
    this->x = x;
    this->y = y;
    this->font = font;
    this->n_lines = 0;
    this->n_cols = 0;
    this->cell_size = font->get_cell_size();
    for (int i = 0; i < text.size(); i++) {
        this->add_char(text.at(i));
    }
    
}
StringImage::~StringImage() {
    for (auto img : this->char_images) {
        delete img;
    }
}
void StringImage::draw(SDL_Renderer * renderer) {
    for (auto img : this->char_images) {
        img->draw(renderer);
    }
}
void StringImage::set_x(int x) {
    int delta = x - this->x;
    this->x = x;
    for (int i = 0; i < this->text.size(); i++) {
        Image * img = this->char_images.at(i);
        img->set_x(img->get_x() + delta);
    }
}

void StringImage::set_y(int y) {
    int delta = y - this->y;
    this->y = y;
    for (int i = 0; i < this->text.size(); i++) {
        Image * img = this->char_images.at(i);
        img->set_y(img->get_y() + delta);
    }
}

void StringImage::set_char(int idx, char c) {
    this->char_images.at(x)->set_texture_zone(this->font->get_char(c));
}

size_t StringImage::size() {
    return this->char_images.size();
}
void StringImage::add_char(char c) {
    if (c == '\n') {
            n_lines += 1;
            n_cols = 0;
    } else {
        this->char_images.push_back(
            new Image(
                font->get_char(c),
                x + n_cols * cell_size, y + n_lines * cell_size  
            )
        );
        n_cols += 1;
    }
    
    text.push_back(c);
    
}

void StringImage::set_string(string str) {

}

