#include "Graphics.h"
#include "File.h"


//Graphics functions
SDL_Texture* Graphics::LoadTexture(std::string filePath)
{
	Debug::Log(std::cout, "Attempting to load texture from: " + filePath, LOG_IO);

	//File validation
	//Make sure the path exists. (C++17)
	if (!File::FileExists(filePath))
	{
		//Debug::Log(std::cout, "File does not exist", LOG_ERROR);
		throw std::exception("File does not exist");
	}

	//If the texture exists, load it in.
	SDL_Texture* texture = IMG_LoadTexture(m_renderer, filePath.c_str());

	//If the operation fails, log it and return.
	if (texture == nullptr) { Debug::LogSDLError(); throw std::exception("Texture creation failed"); }

	//Output confirmation, and return the texture.
	Debug::Log(std::cout, "File loaded successfully!", LOG_IO);
	return texture;
}


