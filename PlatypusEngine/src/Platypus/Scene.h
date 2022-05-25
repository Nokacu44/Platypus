#pragma once
#include <SDL.h>
#include "../vendor/entt/entt.hpp"
#include <iostream>
namespace Platypus
{
  class Scene
  {
  public:

    Scene() = default;
    ~Scene() = default;

    void OnUpdate();
    void OnRender();
  private:
    entt::registry m_Registry;
    // friend class Entity;
  };
}
