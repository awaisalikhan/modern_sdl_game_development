#pragma once

#include <SDL/SDL.h>
class Game {
public:
  Game();
  // Initialize the game

  bool initialize();

  // Runs the game loop until the game is over

  void run_loop();

  // Shutdown the game

  void shut_down();

private:
  // Helper functions for the game loop

  void process_input();
  void update_game();
  void generate_output();

  // Window Creation

  SDL_Window *m_Window;

  // Game should continue running

  bool m_is_running;
};
