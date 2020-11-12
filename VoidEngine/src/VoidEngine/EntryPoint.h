#pragma once

#ifdef VD_PLATFORM_WINDOWS

extern VoidEngine::Application* VoidEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = VoidEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
