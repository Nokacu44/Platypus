#pragma once
#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Core.h"
#include "Render2D.h"

namespace Platypus {
  class PLATYPUS_API Texture {
  public:
    static SDL_Texture* loadTexture(const char* texture);
  };

}