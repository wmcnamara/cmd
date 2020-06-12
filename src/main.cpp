#include "Engine.h"

int main (int argc, char *argv[])
{
	//Initialize the game engine
	Engine* engine = new Engine();
	SDL_Texture* tex = engine->LoadTexture("ball.png");
	
	
	engine->Quit();

	return 0;
}