#include <stdio.h> /* printf and fprintf */
#include <SDL2/SDL.h>
#include <sys/time.h>
#include "constants.hxx"
#include "controller.hxx"
#include "entities/myRect.hxx"
#include "utils/timer.hxx"
#include "entities/physics/box.hxx"
#include "entities/physics/particle.hxx"
#include "entities/ui/FPS_counter.hxx"
#include "resource/resource_manager.hxx"
#include "resource/texture_resource.hxx"
#include "resource/font_resource.hxx"
#include "utils/drawables/DrawableGroup.hxx"
#include "entities/sprite.hxx"
#include "drawables/string_image.hxx"
#include <cmath>
#include <cstdlib>
#include "utils/debug.hxx"
/* Sets constants */

#define DELAY 3000


int main (int argc, char **argv)
{
  SDL_Window *window = NULL;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
    return 1;
  }
  YAE_LOG("Loaded SDL");
  
  window = SDL_CreateWindow("SDL Example", /* Title of the SDL window */
			    SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
			    SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
			    WIDTH, /* Width of the window in pixels */
			    HEIGHT, /* Height of the window in pixels */
			    0); /* Additional flag(s) */

  if (window == NULL) {
    fprintf(stderr, "SDL window failed to initialise: %s\n", SDL_GetError());
    return 1;
  }
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  /**
   * Loading assets
   */
  ResourceManager * resources = new ResourceManager();
  resources->add_and_load("zigTexture", new TextureResource("resources/graphics/fonts/zig_green_size16_cell18.bmp", renderer), TEXTURE_RESOURCE);
  //FontResource(SDL_Renderer * renderer, TextureResource * texture, uint8_t char_size, uint8_t cell_size, uint8_t inter_char_size)
  resources->add_and_load("zigFont", new FontResource(
    renderer, (TextureResource *)resources->get("zigTexture"), 16, 18, 4
  ), TEXTURE_RESOURCE);
  YAE_LOG("Done loading font\n");
  uint32_t frame_time = (int)(1000.0f / TARGET_FPS);
  bool keep_window_open = true;

  timeval t0, t1;
  double dt = 0;
  double total_time = 0;
  uint32_t dt_millis;
  uint32_t delay_time;
  SDL_Event e;


  std::vector<Entity *> root;
  
  root.push_back(
    new FPSCounter(10, 10, 4, (FontResource *)resources->get("zigFont"), 0.2)
  );
  printf("before");

  gettimeofday(&t0, NULL);
  while(keep_window_open) {

      while(SDL_PollEvent(&e) > 0)
      {
          switch(e.type)
          {
              case SDL_QUIT:
                  keep_window_open = false;
                  break;
              case SDL_KEYDOWN:
                  //handle_keydown(&e, player);
                  break;
              case SDL_KEYUP:
                  //handle_keyup(&e, player);
                  break;
                  
          }
      }
      for (auto entity : root) {
        entity->step(dt);
      }
      


      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);

      for (auto entity : root) {
        entity->draw(renderer);
      }
      SDL_RenderPresent(renderer);

      
      //printf("dt=%lf\n", dt);
      gettimeofday(&t1, NULL);
      dt = (double)(t1.tv_usec - t0.tv_usec) / 1000000 + (double)(t1.tv_sec - t0.tv_sec);
      t0 = t1;
      dt_millis = (int)(dt * 1000);
      if (frame_time > dt_millis) {
        //SDL_Delay(frame_time - dt_millis);
      }

  }
  for (auto entity : root) {
    delete entity;
  }

  /* Frees memory */
  delete resources;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  
  /* Shuts down all SDL subsystems */
  SDL_Quit(); 
  
  return 0;
}