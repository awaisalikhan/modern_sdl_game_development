#include "Game.h"
#include <iostream>

Game::Game() : game_running(false), m_Window(nullptr), m_Renderer(nullptr) {}

Game::~Game() = default;

bool Game::init(const char *title, int x_pos, int y_pox, int width, int height,
                bool fullscreen) {

  const Uint32 flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

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

  SDL_RenderPresent(m_Renderer);
}

void Game::clean() {

  std::cout << "Clearing game.\n";

  SDL_DestroyRenderer(m_Renderer);
  SDL_DestroyWindow(m_Window);
  m_Renderer = nullptr;
  m_Window = nullptr;
  game_running = false;
  SDL_Quit();
}

void Game::update() {
  // Game state updates will go here.
}

bool Game::is_game_running() const { return game_running; }

void Game::handle_events() {

  SDL_Event event;

  if (SDL_PollEvent(&event)) {

    switch (event.type) {

    case SDL_QUIT:
      game_running = false;
      break;

    default:
      break;
    }
  }
}
