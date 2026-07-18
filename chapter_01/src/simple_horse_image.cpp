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

  SDL_Surface *p_tmp_surface = SDL_LoadBMP("../assets/images/rider.bmp");

  m_Texture = SDL_CreateTextureFromSurface(m_Renderer, p_tmp_surface);

  SDL_FreeSurface(p_tmp_surface);

  SDL_QueryTexture(m_Texture, NULL, NULL, &m_source_rectangle.w,
                   &m_source_rectangle.h);

  m_destination_rectangle.x = m_source_rectangle.x = 0;
  m_destination_rectangle.y = m_source_rectangle.y = 0;
  m_destination_rectangle.w = m_source_rectangle.w;
  m_destination_rectangle.h = m_source_rectangle.h;

  game_running = true;

  return true;
}

void Game::render() {

  SDL_RenderClear(m_Renderer);
  SDL_RenderCopy(m_Renderer, m_Texture, &m_source_rectangle,
                 &m_destination_rectangle);
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
