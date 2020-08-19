#pragma once

#include <SDL.h>
class Collision
{

	Collision();

public:
	bool CheckCollision(SDL_Rect A, SDL_Rect B);
};

