#pragma once

#ifdef VD_PLATFORM_WINDOWS

extern VoidEngine::Application* VoidEngine::CreateApplication();

int main(int argc, char** argv)
{
	VoidEngine::Log::Init(); 
	VD_CORE_WARN("initialized Log!");
	VD_INFO("=== Welcome to Void Engine! ===");

	auto app = VoidEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
