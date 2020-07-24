#pragma once
#include <SDL.h>
#include <SDL_image.h>


class Entity
{
public:
	Entity(float nX, float nY, int w, int h, SDL_Texture* tex);
	float x, y;
	SDL_Texture* texture;
	SDL_Rect currentFrame;
private:
};

