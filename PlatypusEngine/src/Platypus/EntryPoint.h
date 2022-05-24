#pragma once

#ifdef PLATYPUS_PLATFORM_WINDOWS

extern Platypus::Application* Platypus::CreateApplication();

int main(int argc, char** argv)
{
  auto app = Platypus::CreateApplication();
  app->Run();
  delete app;
}

#else 
  
#endif