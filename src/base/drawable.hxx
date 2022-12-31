#pragma once
#include <SDL2/SDL.h>
/**
 * @brief Drawable abstract class
 * Represents anything that must be drawn on screen using
 * its draw method.
 */
class Drawable {
    public:

        /**
         * @brief Method that must be implemented to give drawing capabilities.
         * @param renderer is the SDL struct currently used for drawing in the window.
         */
        virtual void draw(SDL_Renderer * renderer) = 0;

        /**
         * @brief Get the x position of the drawable
         * @return double the x position
         */
        virtual double get_x();

        /**
         * @brief Get the y position of the drawable
         * @return double the y position
         */
        virtual double get_y();
        
        /**
         * @brief Set the x position of the drawable
         * @param x which value to set x to.
         */
        virtual void set_x(double x);

        /**
         * @brief Set the y position of the drawable
         * @param y which value to set y to.
         */
        virtual void set_y(double y);
        virtual ~Drawable() {};
    protected:
        /**
         * @brief x position on the window.
         */
        double x;
        /**
         * @brief y position of the window.
         */
        double y;
    private:
};