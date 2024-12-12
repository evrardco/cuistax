#include "string_image.hxx"
#include <string>
#include <vector>
#include "../resource/font_resource.hxx"
#include "../cuistax/cui_debug.hxx"
#include <algorithm>
using namespace std;


StringImage::StringImage(FontResource * font, string text, int x, int y) {
    this->x = x;
    this->y = y;
    this->font = font;
    this->n_lines = 1;
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
    this->char_images.at(idx)->set_texture_zone(this->font->get_char(c));
    this->text.at(idx) = c;
}

size_t StringImage::size() {
    return this->char_images.size();
}

void StringImage::add_char(char c) {
    if (c == '\n') {
            n_lines += 1;
            line_lengths.push_back(n_cols);
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

void StringImage::strip(size_t n_chars) {
    for (size_t i = 0; i < n_chars; i++) {
        char c = text.at(text.size() - 1);
        if (c == '\n') {
            n_lines -= 1;
            n_cols = line_lengths.at(line_lengths.size() - 1);
            line_lengths.erase(line_lengths.end() - 1);
        } else {
            n_cols -= 1;    
            delete char_images.at(char_images.size() - 1);
            char_images.erase(char_images.end() - 1);
        } 
        text.erase(text.end() - 1);
    }
}

void StringImage::set_string(string new_str) {
    CUISTAX_DEBUG("new_str length=%ld, text length=%ld", new_str.length(), text.length());
    int delta = new_str.length() - text.length();
    if (delta == 0 && new_str == text) return;
    int abs_delta = delta < 0 ? -delta : delta;
    int replace_idx = delta > 0 ? text.length() : new_str.length();
    
    strip((delta < 0 ) * abs_delta);
    for (int i = 0; i < replace_idx; i++) {
        set_char(i, new_str.at(i));
    } 
    for (int i = replace_idx; i < new_str.length(); i++) {
        add_char(new_str.at(i));
    }
    
}

uint16_t StringImage::get_width() {
    auto max = max_element(line_lengths.begin(), line_lengths.end());
    
    return max != line_lengths.end() ? (* max) * cell_size : n_cols * cell_size;
}

uint16_t StringImage::get_height() {
    return n_cols * cell_size;
}