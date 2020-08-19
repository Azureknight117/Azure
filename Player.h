#pragma once
#include "Entity.h"
#include "Projectile.h"
class Player : public Entity
{
public:
	Player(float nX, float nY, int w, int h);
	Player(float nX, float nY, int w, int h, SDL_Texture* tex);
	Player(float nX, float nY, int w, int h, SDL_Texture* tex, float mHP);
	~Player();
	void SetTex(SDL_Texture* tex);
	void Update(float dt) override;
	void Fire();
	void Destroy() override;

private:
};

