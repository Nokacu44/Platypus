#pragma once

#include <SDL.h>
#include <iostream>
#include "Application.h"
#include "Texture.h"

namespace Platypus
{

  class PLATYPUS_API Render2D
  {
  public:
    Render2D() = default;
    ~Render2D() = default;

    static void DrawSprite(SpriteComponent& sprite, PositionComponent& position);


    static void Begin();
    static void End();


    static void Close();
  private:
    static void Init();
    static SDL_Window* m_Window;
    static SDL_Renderer* m_Renderer;

    friend class Application;
    friend class Texture;
    //friend class Scene;
  };


}

