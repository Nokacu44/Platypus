#include "Scene.h"
#include "Render2D.h"
#include "ECS/Entity.h"


namespace Platypus
{
  void Platypus::Scene::onComponentRender()
  {
    auto group = m_Registry.group<SpriteComponent>(entt::get<PositionComponent>);

    for (auto entity : group)
    {
      auto [sprite, position] = group.get<SpriteComponent, PositionComponent>(entity);

      Render2D::DrawSprite(sprite, position);

    }
  }

  Entity Scene::CreateEntity()
  {
    return { m_Registry.create(),this };
  }


}

