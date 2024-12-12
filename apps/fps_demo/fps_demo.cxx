#include "cuistax/cui_engine.hxx"
#include "flow/scene.hxx"
#include <cstdlib>
#include <cuistax/cuistax.hxx>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {

  cui_context_t ctx;
  ctx.backend_type = CUI_BACKEND_SDL2;
  cui_init(&ctx, 640, 360, "FPS TEST");
  ResourceManager *resources = new ResourceManager();
  resources->add_and_load(
      "zigTexture", new TextureResource(
                        "resources/graphics/fonts/zig_green_size16_cell18.bmp",
                        ctx.backend_ctx.ctx_SDL.renderer));
  // FontResource(SDL_Renderer * renderer, TextureResource * texture, uint8_t
  // char_size, uint8_t cell_size, uint8_t inter_char_size)
  resources->add_and_load(
      "zigFont",
      new FontResource(ctx.backend_ctx.ctx_SDL.renderer,
                       (TextureResource *)resources->get("zigTexture"), 16, 18,
                       4));
  Scene scene;
  FPSCounter counter(
      10, 10, 5, (FontResource *)resources->get("zigFont"), 0.5);
  scene.add_actor(&counter);
  Stage stage(20000 , &ctx, &scene);

  printf("Hello from fps_demo !\n");
  delete resources;
  cui_free_SDL(&ctx.backend_ctx.ctx_SDL);
  return EXIT_SUCCESS;
}