#include <SDL/SDL.h>

SDL_Window *g_pWindow = 0;
SDL_Renderer *g_pRenderer = 0;

int main(int argc, char *argv[]) {

  // Init SDL

  if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {

    // If succeeded create our winwow

    g_pWindow = SDL_CreateWindow(
        "Chatper 1: Setting up SDL", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 800, 600,
        SDL_WINDOW_SHOWN); // If window not created show an error message
    if (g_pWindow != 0) {
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }

  } else {

    return -1;
  }

  // Everything succeeded

  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

  SDL_RenderClear(g_pRenderer);

  SDL_RenderPresent(g_pRenderer);

  SDL_Delay(15000);

  SDL_Quit();
}
