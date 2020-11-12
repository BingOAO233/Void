-- premake5.lua

workspace "VoidEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "VoidEngine"
	location "VoidEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter	"system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"VD_PLATFORM_WINDOWS",
			"VD_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "VD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VD_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"VoidEngine/vendor/spdlog/include",
		"VoidEngine/src"
	}

	links
	{
		"VoidEngine"
	}

	filter	"system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"VD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VD_DIST"
		optimize "On"