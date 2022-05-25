#pragma once
#include <SDL.h>
#include "../Core.h"
namespace Platypus
{

  struct PLATYPUS_API PositionComponent
  {
    int x = 0;
    int y = 0;
    PositionComponent() = default;
    PositionComponent(const int& p_x, const int& p_y) : x(p_x), y(p_y) { }
    PositionComponent(const PositionComponent& positionComponent) = default;
  };


  struct PLATYPUS_API SpriteComponent
  {
    SDL_Texture* texture = nullptr;

    int width = 0;
    int height = 0;

    SpriteComponent() = default;
    SpriteComponent(SDL_Texture * p_texture, int p_width = 0, int p_height = 0) : texture(p_texture) {
      SDL_QueryTexture(texture, NULL, NULL, &width, &height);
      if (p_width > 0) { rect.w = p_width; width = p_width; }
      else rect.w = width;

      if (p_height > 0) { rect.h = p_height; height = p_height; }
      else rect.h = height;

    }

  private:
    SDL_Rect rect{};
    friend class Render2D;
  };

}