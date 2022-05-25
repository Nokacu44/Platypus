#pragma once
#include <SDL.h>
#include "../vendor/entt/entt.hpp"
#include "ECS/Components.h"
#include <iostream>
#include "Core.h"

namespace Platypus
{
  class Entity;

  class PLATYPUS_API Scene
  {
  public:

    Scene() = default;
    virtual ~Scene() = default;

    Entity CreateEntity();

    virtual void OnUpdate() = 0;
    virtual void OnRender() = 0;



  private:
    entt::registry m_Registry;

    void onComponentRender();

    friend class Entity;
    friend class Application;
  };
}
