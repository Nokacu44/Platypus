#pragma once

#ifdef PLATYPUS_PLATFORM_WINDOWS
  #ifdef PLATYPUS_BUILD_DLL
    #define PLATYPUS_API __declspec(dllexport)
  #else 
    #define PLATYPUS_API __declspec(dllimport)
  #endif
#else 
#error Platypus only support Windows!
#endif 