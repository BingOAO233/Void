#include <VoidEngine.h>

class Sandbox : public VoidEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

VoidEngine::Application* VoidEngine::CreateApplication()
{
	return new Sandbox();
}