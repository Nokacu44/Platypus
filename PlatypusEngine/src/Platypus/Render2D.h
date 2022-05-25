#pragma once

#include <SDL.h>
#include <iostream>
#include "Application.h"
namespace Platypus
{

  class Render2D
  {
  public:
    static void Init();
    //static void DrawSprite(SpriteComponent& sprite, PositionComponent& position);


    static void Begin();
    static void End();

    Render2D() = default;
    ~Render2D() = default;


    static void Close();
  private:
    static SDL_Window* m_Window;
    static SDL_Renderer* m_Renderer;

    //friend class Scene;
  };
}

