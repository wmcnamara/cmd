#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <Windows.h>
#include <sstream>

#include "Node.h"
#include "File.h"

#undef CreateWindow
class Graphics 
{
public:
	//Loads texture and returns it.
	SDL_Texture* LoadTexture(std::string filePath);

private:
	//Render tree. Anything added to here will be outputted to the screen.
	Node* m_renderNode;

	//The renderer currently drawing to m_window.
	SDL_Renderer* m_renderer = nullptr;
};