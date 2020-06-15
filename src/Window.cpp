#include "Window.h"

Window::Window(int xSize, int ySize) : m_scrWidth(xSize), m_scrHeight(ySize)
{
	///////////////////
	/*Window Renderer*/
	///////////////////

	Debug::Log(std::cout, "Attempting to create a window...", LOG_INIT);
	//Resolution variables.
	SDL_Window* window = SDL_CreateWindow("Pong",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_scrWidth, m_scrHeight,
		SDL_WINDOW_FULLSCREEN);

	//If creation fails
	if (window == nullptr) { Debug::Log(std::cout, "Window creation failed", LOG_ERROR); }

	Debug::Log(std::cout, "Window created successfully!", LOG_INIT);
	//Set member variable and return it.
	m_window = window;

	/////////////////
	/*Init Renderer*/
	/////////////////

	SDL_Renderer* ren = nullptr;

	//If not just create one.
	ren = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	//Make sure its successful
	if (ren == nullptr) {
		Debug::LogSDLError();
		throw std::exception("Renderer Creation Failed");
	}

	Debug::Log(std::cout, "Renderer Created Successfully!", LOG_INIT);
}

