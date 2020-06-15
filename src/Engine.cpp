#include "Engine.h"

//Initializes engine. Returns false if error is thrown
Engine::Engine()
{
	Debug::Log(std::cout, "Attempting to start SDL...", LOG_INIT);

	//Initialize SDL
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		Debug::Log(std::cout, "SDL Initialized Successfully", LOG_INIT);
	}
	else 
	{ 
		Debug::LogSDLError();
		return;
	}

	//Initialize the rendernode.
	//m_renderNode = new Node();
	Debug::Log(std::cout, "Render Node Created Successfully!", LOG_INIT);

	Debug::Log(std::cout, "Initialization Completed With No Errors \n", LOG_INIT);
	return;
}

void Engine::Quit()
{
	SDL_Quit();
}



