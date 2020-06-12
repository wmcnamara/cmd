#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <vector>
#include <filesystem>
#include <memory>

#include "Debug.h"
#include "Node.h"

//Platform specific code
#ifdef _WIN32
	#define DIR_SEP "\\"
	#define WIN_CONSOLE
#elif // TODO
	#define DIR_SEP "/"
#endif

#undef main
#undef CreateWindow

namespace fs = std::filesystem;

class Engine final
{
public:
	//Initializes the engine.
	Engine();

	//Quits the program.
	void Quit();

	//Creates an SDL window.
	SDL_Window* CreateWindow();

	//Creates an SDL renderer.
	SDL_Renderer* CreateRenderer();

	//Grabs the desktop resolution. Can be used as a "default resolution".
	static void GetDesktopResolution(int& horizontal, int& vertical);

	//Sets the programs current resolution to horizontal and vertical.
	void GetProgramResolution(int& width, int& height) { width = m_scrWidth; height = m_scrHeight; }

	//Returns current renderer. 
	const SDL_Renderer* GetRenderer() { if (m_renderer != nullptr) return m_renderer; }

	//Returns window
	const SDL_Window* GetWindow() { if (m_window != nullptr) return m_window; }

	//Returns a string to the resource path
	std::string GetResourceFilePath() { return m_resourceFilePath; }

	//Returns true if file exists at path.
	bool FileExists(std::string directory) { return fs::exists(directory); }

	//Loads texture into memory.
	SDL_Texture* LoadTexture(std::string fileName);

private:
	//The window that is currently being drawn to.
	SDL_Window* m_window = nullptr;

	//The renderer currently drawing to m_window.
	SDL_Renderer* m_renderer = nullptr;

	//The programs screen resolution
	int m_scrWidth = 0, m_scrHeight = 0;

	//Persistent filepath to the base path of the game.
	const std::string m_baseFilePath = SDL_GetBasePath();

	//A persistent filepath to game resources
	const std::string m_resourceFilePath = m_baseFilePath + "data" + DIR_SEP;

	//Render tree. Anything added to here will be outputted to the screen.
	Node* m_renderNode;
};