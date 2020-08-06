#include "Player.h"


Player::Player(float nX, float nY, int nW, int nH)
{
	transform.x = nX;
	transform.y = nY;
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = nW;
	currentFrame.h = nH;
}
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

void Player::Update(float dt)
{
	Entity::Update(dt);
}

void Player::Draw(){}

void Player::Clean(){}

void Player::SetTex(SDL_Texture* tex)
{
	texture = tex;
}