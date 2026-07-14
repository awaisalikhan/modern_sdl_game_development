#include <SDL/SDL.h>

SDL_Window *g_pWindow = 0;
SDL_Renderer *g_pRenderer = 0;

bool is_game_running = false;

void init();
void handle_events();
void render();
void clean();
void update();

bool init(const char *title, int x, int y, int w, int h, int flags) {

  // Init SDL

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

    // If succeeded create our winwow

    g_pWindow = SDL_CreateWindow(title, x, y, w, h, flags);

    if (g_pWindow) {

      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);

      if (g_pRenderer) {

        return true;
      } else {

        SDL_Log("SDL Window creation failed: %s", SDL_GetError());
        return false;
      }

    } else {

      SDL_Log("SDL Window creation failed: %s", SDL_GetError());
      return false;
    }

  } else {

    SDL_Log("SDL Window creation failed: %s", SDL_GetError());
    return false;
  }
}

void render() {

  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

  SDL_RenderClear(g_pRenderer);

  SDL_RenderPresent(g_pRenderer);

  SDL_Delay(15);
}

int main(int argc, char *argv[]) {

  init();

  while (is_game_running) {

    handle_events();
    update();
    render();
  }

  clean();

  if (init("SDL Game Development", SDL_WINDOWPOS_CENTERED,
           SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN)) {

    is_game_running = true;
  }

  else {

    return 1;
  }

  while (is_game_running) {

    render();
  }

  SDL_Quit();
}
