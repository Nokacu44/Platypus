#include "Application.h"

// debug
#include <iostream>
//
namespace Platypus
{

  int Application::SCREEN_WIDTH = 0;
  int Application::SCREEN_HEIGHT = 0;
  char* Application::TITLE = "Game";
  Application::Application(char* name, int const width, int const height)
  {
    TITLE = name;
    SCREEN_WIDTH = width;
    SCREEN_HEIGHT = height;

    if (initSDLStuff())
    {
      // Init Renderer
      Render2D::Init();

    }



  }

  void Application::Run()
  {
    running = true;
    gameLoop();
  }

  void Application::gameLoop()
  {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    while (running != false) {
      frameStart = SDL_GetTicks();

      // Scene handleEvents();

      //PROVA
      SDL_Event event;
      SDL_PollEvent(&event);

      if (event.type == SDL_QUIT) {
        running = false;
      }
      
      if (firstScene == nullptr) std::cout << "HEY" << std::endl;

      firstScene->OnUpdate();

      Render2D::Begin();

      firstScene->OnRender();
      firstScene->onComponentRender();
      Render2D::End();

      frameTime = SDL_GetTicks() - frameStart;
      if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
      }
    }
  }

  bool Application::initSDLStuff()
  {
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0) std::cout << "Hey SDL_Init has failed. SDL ERROR: " << SDL_GetError() << std::endl;

    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted = IMG_Init(flags);
    if ((initted & flags) != flags) {
      printf("IMG_Init: Failed to init required jpg and png support!\n");
      printf("IMG_Init: %s\n", IMG_GetError());
      // handle error
      // ...
    }

    return true;
  }


  Application::~Application()
  {
    Render2D::Close();
    SDL_Quit();
  }

}