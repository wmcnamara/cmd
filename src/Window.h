#pragma once
#include "SDL.h"
#include "Debug.h"

class Window
{
public:
	//Creates an SDL window.
	Window(int xSize, int ySize);

	//Returns current renderer. 
	const SDL_Renderer* GetRenderer() { if (m_renderer != nullptr) return m_renderer; }

	//Returns window
	const SDL_Window* GetWindow() { if (m_window != nullptr) return m_window; }

	//Sets the programs current resolution to horizontal and vertical.
	void GetProgramResolution(int& width, int& height) { width = m_scrWidth; height = m_scrHeight; }
private:
	SDL_Window* m_window;

	//The renderer currently drawing to m_window.
	SDL_Renderer* m_renderer = nullptr;

	//The programs screen resolution
	int m_scrWidth = 0, m_scrHeight = 0;
};

