#include "Platypus.h"

Platypus::Entity entity;
class MainScene : virtual public Platypus::Scene
{
public:
  MainScene() {

    entity = this->CreateEntity();
    entity.AddComponent<Platypus::SpriteComponent>(Platypus::Texture::loadTexture("./assets/cowboy.png"), 128, 128);
    entity.AddComponent<Platypus::PositionComponent>(100, 100);
   }

  void OnUpdate() override
  {
    entity.GetComponent<Platypus::PositionComponent>().x += 1;
  }

  void OnRender() override
  {

  }
};

class SandBox : virtual public Platypus::Application
{
public:

  SandBox (char* title,int const width,int const height) 
  : Application::Application(title, width, height)
  {
    firstScene = new MainScene();
  }
  ~SandBox()
  {

  }
};



Platypus::Application* Platypus::CreateApplication()
{
  return new SandBox("PLATYPUS GAME YEE", 800, 600);
}



