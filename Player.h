#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(float nX, float nY, int w, int h);
	Player(float nX, float nY, int w, int h, SDL_Texture* tex);
	
	void SetTex(SDL_Texture* tex);
	void Update(float dt) override;
	void Draw() override;
	void Clean() override;
private:
};

