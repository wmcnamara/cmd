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
#include "Graphics.h"

//Platform specific code
#ifdef _WIN32
#define DIR_SEP "\\"
#elif
#define DIR_SEP "/"
#endif

namespace fs = std::filesystem;

#undef main
#undef CreateWindow
class Engine final
{
public:
	//Initializes the engine.
	Engine();

	//Quits the program.
	void Quit();

	//Returns a string to the resource path
	std::string GetResourceFilePath() { return m_resourceFilePath; }

	//Returns a string to the base file path.
	std::string GetBaseFilePath() { return m_baseFilePath; }

	//Returns a constant reference to the graphics class.
	Graphics& GFX() const { return *m_graphics; }
private:
	//Persistent filepath to the base path of the game.
	const std::string m_baseFilePath = SDL_GetBasePath();

	//A persistent filepath to game resources
	const std::string m_resourceFilePath = m_baseFilePath + "data" + DIR_SEP;

	//Instance of the graphics class. 
	Graphics* m_graphics;
};