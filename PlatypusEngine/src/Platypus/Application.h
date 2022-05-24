#pragma once

#include "Core.h"

namespace Platypus {
  class PLATYPUS_API Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();
  };


  // To define in client
  Application* CreateApplication();


}


