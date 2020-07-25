#include "Player.h"

Player::Player(float nX, float nY, int nW, int nH, SDL_Texture* tex)
{
	transform.x = nX;
	transform.y = nY;
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = nW;
	currentFrame.h = nH;
	texture = tex;
}