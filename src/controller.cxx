#include "controller.hxx"
#include "constants.hxx"
void handle_keyup(SDL_Event * evt, MyRect& player) {
  switch (evt->key.keysym.sym) {
    case SDLK_UP:
      player.set_vy(0);
      break;
    case SDLK_DOWN:
      player.set_vy(0);
      break;
    case SDLK_LEFT:
      player.set_vx(0);
      break;
    case SDLK_RIGHT:
      player.set_vx(0);
      break;
    default:
      printf("keyup: %d\n", evt->key.keysym.sym);
      break;
    }
}
void handle_keydown(SDL_Event * evt, MyRect& player) {
  switch (evt->key.keysym.sym) {
    case SDLK_UP:
      player.set_vy(-PLAYER_SPEED);
      break;
    case SDLK_DOWN:
      player.set_vy(PLAYER_SPEED);
      break;
    case SDLK_LEFT:
      player.set_vx(-PLAYER_SPEED);
      break;
    case SDLK_RIGHT:
      player.set_vx(PLAYER_SPEED);
      break;
    default:
    printf("keydown: %d\n", evt->key.keysym.sym);
      break;
    }
}