#include "Game.h"

Game *m_game;

int main(int argc, char *argv[]) {

  m_game = new Game();

  m_game->init("Chapter 1", 100, 100, 800, 600, 0);

  while (m_game->is_game_running()) {

    m_game->handle_events();
    m_game->update();
    m_game->render();
  }

  m_game->clean();

  return 0;
}
