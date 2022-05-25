#pragma once

#include "Core.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Scene.h"
#include "Render2D.h"

namespace Platypus {
  class PLATYPUS_API Application
  {
  public:
    Application(char* name, int const width, int const height);
    virtual ~Application();

    void Run();

    Scene* firstScene = nullptr;

    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    static char* TITLE;
  private:

    Application();
    bool initSDLStuff();
    bool running = false;
    inline void gameLoop();

  };

  // To define in client
  Application* CreateApplication();

}


