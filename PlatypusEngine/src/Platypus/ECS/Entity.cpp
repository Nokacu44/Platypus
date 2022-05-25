#include "Entity.h"

namespace Platypus
{
  Entity::Entity(entt::entity handle, Scene* scene)
    : m_EntityHandle(handle), m_Scene(scene) {}

}