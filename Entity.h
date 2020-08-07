#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Transform.h"
#include "Health.h"

class Entity
{
public:
	Entity();
	Entity(float nX, float nY, int w, int h, SDL_Texture* tex);
	Entity(float nX, float nY, int w, int h, SDL_Texture* tex, float mHP);
	~Entity();

	Transform transform;
	Vector2D velocity; 
	SDL_Texture* texture;
	SDL_Rect currentFrame;
	double rotation = 0;
	SDL_Point center;
	SDL_RendererFlip flip;
	virtual void Draw();
	virtual void Clean();
	virtual void Update(float dt);

	float speed = .05;
	Health* health;
	virtual void Destroy();
	int CreateAnim(int r, int w, int h, int amount, int speed);
	void SetCurAnimation(int a) { beginAnim = 0; curAnim = a; }
	void UpdateAnimation();
private:
	struct anim {
		int index;
		int w;
		int h;
		int amount;
		int frame;
		int speed;
	};
	std::vector<anim> animations;
	int curAnim;
	int beginAnim;
	bool rev, nAb = false;
	int newAnim;
};

