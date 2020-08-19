#pragma once
#include "Entity.h"
class Projectile : public Entity
{
public:
	Projectile(float nX, float nY, int w, int h, SDL_Texture* tex);
	~Projectile();
	void Update(float dt) override;
};

