#pragma once
#include <SDL/SDL.h>

class Game {

public:
  Game();
  ~Game();

  bool init(const char *title, int x_pos, int y_pox, int width, int height,
            int flags);
  void handle_events();
  void render();
  void clean();
  void update();

  bool is_game_running();

private:
  bool game_running;

  SDL_Window *m_Window;
  SDL_Renderer *m_Renderer;
};
