#include "Game.h"

Game::Game() : m_Window(nullptr), m_is_running(false) {}

bool Game::initialize() {

  int sdl_result = SDL_Init(SDL_INIT_VIDEO);

  if (sdl_result != 0) {

    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return false;
  }

  m_Window = SDL_CreateWindow("Chapter 1", 100, 100, 1024, 768, 0);

  if (!m_Window) {

    SDL_Log("Failed to create window: %s", SDL_GetError());
    SDL_Quit();
    return false;
  }

  m_is_running = true;
  return true;
}

void Game::run_loop() {

  while (m_is_running) {

    process_input();
    update_game();
    generate_output();
    SDL_Delay(1);
  }
}

void Game::process_input() {

  SDL_Event event;

  while (SDL_PollEvent(&event)) {

    switch (event.type) {

    case SDL_QUIT:
      m_is_running = false;
      break;
    }
  }

  const Uint8 *state = SDL_GetKeyboardState(nullptr);

  if (state[SDL_SCANCODE_ESCAPE]) {

    m_is_running = false;
  }
}

void Game::update_game() {}

void Game::generate_output() {}

void Game::shut_down() {

  SDL_DestroyWindow(m_Window);
  SDL_Quit();
}

int main(int, char **) {

  Game game;

  bool success = game.initialize();

  if (success) {

    game.run_loop();
  }

  game.shut_down();

  return 0;
}
