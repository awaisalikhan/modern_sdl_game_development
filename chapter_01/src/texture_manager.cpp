#include "texture_manager.h"
#include <SDL_image.h>

bool TextureManager::load(std::string file_name, std::string id,
                          SDL_Renderer *p_renderer) {

  SDL_Surface *p_temp_surface = IMG_Load(file_name.c_str());

  if (p_temp_surface == 0) {

    return false;
  }

  SDL_Texture *p_texture =
      SDL_CreateTextureFromSurface(p_renderer, p_temp_surface);

  SDL_FreeSurface(p_temp_surface);

  if (p_texture != 0) {

    m_texture_map[id] = p_texture;
    return true;
  }

  return false;
}
