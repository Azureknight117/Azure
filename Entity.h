#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2D.h"

class Entity
{
public:
	Entity();
	Entity(float nX, float nY, int w, int h, SDL_Texture* tex);
	Vector2D transform;
	SDL_Texture* texture;
	SDL_Rect currentFrame;
private:
};

