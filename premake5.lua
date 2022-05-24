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
    "%{prj.name}/vendor"
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

    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
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
    "PlatypusEngine/src"
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