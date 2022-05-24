#include "Platypus.h"


class SandBox : public Platypus::Application
{
public:
  SandBox()
  {

  }
  ~SandBox()
  {

  }
};

Platypus::Application* Platypus::CreateApplication()
{
  return new SandBox();
}

