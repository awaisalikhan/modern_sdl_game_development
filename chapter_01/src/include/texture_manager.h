#pragma once
#include <SDL/SDL.h>
#include <map>
#include <string>

class TextureManager {

  TextureManager();
  ~TextureManager();

public:
  bool load(std::string file_name, std::string id, SDL_Renderer *p_renderer);

  void draw(std::string, int x, int y, int width, int height,
            SDL_Renderer *p_renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void drawFrame(std::string, int x, int y, int width, int height,
                 SDL_Renderer *p_renderer, int current_row, int current_frame,
                 SDL_RendererFlip flip = SDL_FLIP_NONE);

  std::map<std::string, SDL_Texture *> m_texture_map;
};
