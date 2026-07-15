#include "Game.h"

Game *m_game;

int main(int, char *[]) {

  m_game = new Game();

  const bool fullscreen = false;

  if (!m_game->init("Chapter 1", 100, 100, 800, 600, fullscreen)) {
    delete m_game;
    return 1;
  }

  while (m_game->is_game_running()) {

    m_game->handle_events();
    m_game->update();
    m_game->render();
  }

  m_game->clean();
  delete m_game;

  return 0;
}
