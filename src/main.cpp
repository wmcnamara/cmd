#include "Engine.h"
#include "Object.h"
#include "Window.h"
int main (int argc, char *argv[])
{
	//Initialize the game engine
	std::unique_ptr<Window> window = std::make_unique<Window>(800, 600);
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	
	Object* node = new Object((engine->GFX().LoadTexture("ball.png")));
	engine->Quit();
	return 0;
}