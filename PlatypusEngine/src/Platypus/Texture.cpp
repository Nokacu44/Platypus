#include "Texture.h"
#include "Render2D.h"

namespace Platypus
{
  SDL_Texture* Texture::loadTexture(const char* texture)
  {
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* t = SDL_CreateTextureFromSurface(Render2D::m_Renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return t;
  }
}