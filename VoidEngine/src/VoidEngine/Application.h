#pragma once

#include "Core.h"

namespace VoidEngine
{

	class VOID_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();	
	};

	// To be defined in client
	Application* CreateApplication();

}

