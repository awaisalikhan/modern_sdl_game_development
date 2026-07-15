#include "Game.h"
#include <iostream>

bool Game::init(const char *title, int x_pos, int y_pox, int width, int height,
                int flags) {

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

    std::cout << "SDL init success.\n";

    m_Window = SDL_CreateWindow(title, x_pos, y_pox, width, height, flags);

    if (m_Window != 0) {

      std::cout << "Window creation success.\n";
      m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);

      if (m_Renderer != 0) {

        std::cout << "Renderer creation success.\n";
        SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
      }

      else {

        std::cout << "Render creation failed.\n";
        return false;
      }
    } else {
      std::cout << "Window creation failed.\n";
      return false;
    }
  } else

  {
    std::cout << "SDL Init failed.\n";
    return false;
  }

  game_running = true;

  return true;
}

void Game::render() {

  SDL_RenderClear(m_Renderer);

  SDL_Draw
}
