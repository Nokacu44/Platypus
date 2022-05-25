#include "Scene.h"
#include "Render2D.h"
void Platypus::Scene::OnUpdate()
{
  static int c = 0;
  std::cout << c++ << std::endl;
}

void Platypus::Scene::OnRender()
{
  Render2D::Begin();


  Render2D::End();
}