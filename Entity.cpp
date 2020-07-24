#include "Entity.h"

Entity::Entity(float nX, float nY, int nW, int nH, SDL_Texture* tex)
	:x(nX), y(nY), texture(tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = nW;
	currentFrame.h = nH;
}