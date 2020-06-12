#include "Engine.h"

//Initializes engine. Returns false if error is thrown
Engine::Engine()
{
	Log(std::cout, "Attempting to start SDL...", LOG_INIT);

	//Initialize SDL
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		Log(std::cout, "SDL Initialized Successfully", LOG_INIT);
	}
	else 
	{ 
		LogSDLError();
		return;
	}

	//Create a window
	CreateWindow();
	CreateRenderer();

	//Initialize the rendernode.
	m_renderNode = new Node();
	Log(std::cout, "Render Node Created Successfully", LOG_INIT);

	Log(std::cout, "Initialization Completed With No Errors \n", LOG_INIT);
	return;
}

void Engine::Quit()
{
	SDL_Quit();
}

Window Engine::CreateWindow()
{
	Log(std::cout, "Attempting to create a window...", LOG_INIT);

	//Resolution variables.
	GetDesktopResolution(m_scrWidth, m_scrHeight);
	SDL_Window* window = SDL_CreateWindow("Pong",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_scrWidth, m_scrHeight,
		SDL_WINDOW_FULLSCREEN);

	//If creation fails
	if (window == nullptr) { Log(std::cout, "Window creation failed", LOG_ERROR); }

	Log(std::cout, "Window creation successful!", LOG_INIT);
	//Set member variable and return it.
	m_window = window;
	return window;
}

void Engine::GetDesktopResolution(int& horizontal, int& vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop

	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;

	//Create a log statement
	std::stringstream logStatement;
	logStatement << "Desktop resolution : " << horizontal << " x " << vertical;

	Log(std::cout, logStatement.str(), LOG_INIT);
}

void Engine::LogSDLError()
{
	std::cout << "SDL Error: " << SDL_GetError() << std::endl;
}

void Engine::Log(std::ostream & stream, std::string msg, LogType T)
{
	switch (T)
	{
		case LOG_MESSAGE:
			stream << "Message: " << msg << std::endl;
			break;
		case LOG_WARNING:
			stream << "Warning: " << msg << std::endl;
			break;
		case LOG_ERROR:
			stream << "Error: " << msg << std::endl;
			break;
		case LOG_IO:
			stream << "File IO: " << msg << std::endl;
			break;
		case LOG_INIT:
			stream << "Init: " << msg << std::endl;
		case LOG_CREATION:
			stream << "Creation: " << msg << std::endl;
	}
}

//Graphics functions
Texture Engine::LoadTexture(std::string fileName)
{
	Log(std::cout, "Attempting to load texture from: " + GetResourceFilePath() + fileName, LOG_IO);

	//Make sure the path exists. (C++17)
	if (!FileExists(GetResourceFilePath() + fileName)) 
	{
		Log(std::cout, "File does not exist", LOG_ERROR);
	}

	//TODO this line is disgusting and needs to be changed
	Texture texture = IMG_LoadTexture(m_renderer, std::string(GetResourceFilePath().c_str() + fileName).c_str());
	
	//If the operation fails, log it and return.
	if (texture == nullptr) { LogSDLError(); return nullptr; }

	//Output confirmation, and return the texture.
	Log(std::cout, "File Successfully loaded", LOG_IO);
	return texture;	
}

Renderer Engine::CreateRenderer()
{
	//If they use it prematurely output this.
	if (m_window == nullptr) { Log(std::cout, "Initialise a window first!", LOG_ERROR); }

	Renderer ren = nullptr;

	//If this is the first renderer, set it as the default.
	if (m_renderer == nullptr)
	{
		ren = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
		m_renderer = ren;
	}
	else
	{
		//If not just create one.
		ren = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	}

	//Make sure its successful
	if (ren == nullptr) {
		LogSDLError();
		return nullptr;
	}

	Log(std::cout, "Renderer Created Successfully!", LOG_INIT);
	return ren;
}