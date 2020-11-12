#pragma once

#ifdef VD_PLATFORM_WINDOWS
	#ifdef VD_BUILD_DLL
		#define VOID_API __declspec(dllexport)
	#else
		#define VOID_API __declspec(dllimport)
	#endif
#else
	#error Void Only Support Windows!
#endif
