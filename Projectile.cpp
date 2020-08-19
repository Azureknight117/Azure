#include "Projectile.h"

Projectile::Projectile(float nX, float nY, int w, int h, SDL_Texture* tex)
{
	transform.x = nX;
	transform.y = nY;
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = w;
	currentFrame.h = h;
	texture = tex;
	health = new Health(0);
}
Projectile::~Projectile() {}

void Projectile::Update(float dt)
{
	Entity::Update(dt);
}