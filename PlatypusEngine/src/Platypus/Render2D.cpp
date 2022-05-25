#include "Render2D.h"

namespace Platypus
{
  SDL_Renderer* Render2D::m_Renderer = nullptr;
  SDL_Window* Render2D::m_Window = nullptr;

  void Render2D::Init()
  {
    m_Window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Application::SCREEN_WIDTH, Application::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (m_Window == nullptr) { std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl; }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    if (m_Renderer == nullptr) { std::cout << "Renderer failed to init. Error: " << SDL_GetError() << std::endl; }

    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0);
  }

  void Render2D::Begin()
  {
    SDL_RenderClear(m_Renderer);
  }

  void Render2D::End()
  {
    SDL_RenderPresent(m_Renderer);
  }

  void Render2D::Close()
  {
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(m_Renderer);
  }

}