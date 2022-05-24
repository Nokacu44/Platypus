#pragma once

#ifdef PLATYPUS_PLATFORM_WINDOWS
extern Platypus::Application* Platypus::CreateApplication();
// soluzione ad errore LNK2019 da: https://stackoverflow.com/questions/24620143/error-lnk2019-unresolved-external-symbol-main-referenced-in-function-tmainc
#undef main
// -------------------------------------------------
int main(int argc, char* argv[])
{
  auto app = Platypus::CreateApplication();
  app->Run();
  delete app;
  return 0;
}

  
#endif