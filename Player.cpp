#include "Player.h"


Player::Player(float nX, float nY, int nW, int nH)
{
	transform.x = nX;
	transform.y = nY;
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = nW;
	currentFrame.h = nH;
	health = new Health(100);
}
Player::Player(float nX, float nY, int nW, int nH,  SDL_Texture* tex)
{
	transform.x = nX;
	transform.y = nY;
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = nW;
	currentFrame.h = nH;
	texture = tex;
	health = new Health(100);
}

Player::Player(float nX, float nY, int nW, int nH, SDL_Texture* tex, float mHP)
{
	transform.x = nX;
	transform.y = nY;
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = nW;
	currentFrame.h = nH;
	texture = tex;
	health = new Health(mHP);
}

Player::~Player()
{
}


void Player::Update(float dt)
{
	Entity::Update(dt);
}


void Player::SetTex(SDL_Texture* tex)
{
	texture = tex;
}

void Player::Fire()
{

}

void Player::Destroy()
{

}