#include <stdio.h> /* printf and fprintf */
#include <SDL2/SDL.h>
#include <sys/time.h>
#include "constants.hxx"
#include "controller.hxx"
#include "entities/myRect.hxx"
#include "utils/timer.hxx"
#include "entities/node.hxx"
/* Sets constants */
#define WIDTH 800
#define HEIGHT 600
#define DELAY 3000


int main (int argc, char **argv)
{
  SDL_Window *window = NULL;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
    return 1;
  }

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

  uint32_t frame_time = (int)(TARGET_FPS / 60.0f);
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  bool keep_window_open = true;


  timeval t0, t1;
  double dt = 0;
  uint32_t dt_millis;
  uint32_t delay_time;
  SDL_Event e;

  Group root(true);

  MyRect player(renderer, WIDTH/2, HEIGHT/2, 30, 30);
  Timer center_timer(
    5.0, 
    [&player](void){player.set_x(WIDTH/2); player.set_y(HEIGHT/2); printf("Firing!\n");},
    REPEAT,
    true
  );

  root.push_back(&player);

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
                  handle_keydown(&e, player);
                  break;
              case SDL_KEYUP:
                  handle_keyup(&e, player);
                  break;
                  
          }
      }

      root.step(dt);
      center_timer.step(dt);

      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);
      root.draw(renderer);


      SDL_RenderPresent(renderer);
      
      //printf("dt=%lf\n", dt);
      gettimeofday(&t1, NULL);
      dt = (double)(t1.tv_usec - t0.tv_usec) / 1000000 + (double)(t1.tv_sec - t0.tv_sec);
      t0 = t1;
      dt_millis = (int)(dt * 1000);
      if (frame_time > dt_millis) {
        SDL_Delay(frame_time - dt_millis);
      }

  }





  /* Frees memory */
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  
  /* Shuts down all SDL subsystems */
  SDL_Quit(); 
  
  return 0;
}