#include "Engine.h"

#include "Window.h"
int main (int argc, char *argv[])
{
	//Initialize the game engine
	std::unique_ptr<Window> window = std::make_unique<Window>();
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	
	Node* node = new Node();
	engine->GFX().LoadTexture("ball.png");
	engine->Quit();
	return 0;
}