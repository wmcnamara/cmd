#pragma once
#include "SDL.h"
#include "Vector3.h"
#include "Node.h"

class Object : public Node
{
public:
	Object(SDL_Texture& tex) : m_texture(&tex) {}

	class Transform {
		Vector3<float> position;
		Vector3<float> rotation;
		Vector3<float> scale;
	};

private:
	SDL_Texture* m_texture;
};

