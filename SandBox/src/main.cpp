#include "Platypus.h"


class SandBox : public Platypus::Application
{
public:

  SandBox (int const width,int const height) 
    : Application::Application(width,height)
  {

  }
  ~SandBox()
  {

  }
};

Platypus::Application* Platypus::CreateApplication()
{
  return new SandBox(800, 600);
}



