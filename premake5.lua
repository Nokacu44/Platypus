workspace "PlatypusGame"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PlatypusEngine"
  
  location "PlatypusEngine"
  kind "SharedLib"
  language "C++"


  targetdir ("bin/".. outputdir .."/%{prj.name}")
  objdir ("bin-int/".. outputdir .."/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "%{prj.name}/vendor",
    "%{prj.name}/vendor/SDL/include",
  }

  libdirs
  {
    "%{prj.name}/vendor/SDL/lib/x64",
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "10.0"

    defines
    {
      "PLATYPUS_PLATFORM_WINDOWS",
      "PLATYPUS_BUILD_DLL"
    }
    

    links
    {
      "SDL2",
    }
    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox"),
    }

  filter "configurations:Debug"
    defines "PLATYPUS_DEBUG"
    symbols "On"

  filter "configurations:Debug"
    defines "PLATYPUS_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "PLATYPUS_DIST"
    optimize "On"
   


project "SandBox"

  location "SandBox"
  kind "ConsoleApp"
  language "C++"


  targetdir ("bin/".. outputdir .."/%{prj.name}")
  objdir ("bin-int/".. outputdir .."/%{prj.name}")


  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "%{prj.name}/vendor",
    "PlatypusEngine/src",
    "PlatypusEngine/vendor/SDL/include"
  }
  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "10.0"

    defines
    {
      "PLATYPUS_PLATFORM_WINDOWS",
    }

    links 
    {
      "PlatypusEngine"
    }



  filter "configurations:Debug"
    defines "PLATYPUS_DEBUG"
    symbols "On" 

  filter "configurations:Debug"
    defines "PLATYPUS_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "PLATYPUS_DIST"
    optimize "On"