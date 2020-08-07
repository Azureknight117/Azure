#include "Entity.h"


Entity::Entity()
{}
Entity::Entity(float nX, float nY, int nW, int nH, SDL_Texture* tex)
	:texture(tex)
{
	transform.x = nX;
	transform.y = nY;
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = nW;
	currentFrame.h = nH;
	center = { nW / 2, nH / 2 };
	speed = 1;
}

Entity::Entity(float nX, float nY, int nW, int nH, SDL_Texture* tex, float mHP)
	:texture(tex)
{
	transform.x = nX;
	transform.y = nY;
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = nW;
	currentFrame.h = nH;
	center = { nW / 2, nH / 2 };
	speed = 1;

	health->InitHealth(mHP);
}

Entity::~Entity()
{
	delete(health);
}

void Entity::Update(float dt)
{
	//UpdateAnimation();
	transform.x += (velocity.x * speed * dt);
	transform.y += (velocity.y * speed * dt);

	if (health->curHealth == 0)
		Destroy();
}

void Entity::Draw()
{

}

void Entity::Clean()
{

}

int Entity::CreateAnim(int r, int w, int h, int amount, int speed)
{
	anim temp;
	temp.index = r;
	temp.w = w;
	temp.h = h;
	temp.amount = amount;
	temp.frame = 0;
	temp.speed = speed;
	animations.push_back(temp);
	return animations.size() - 1;
}

void Entity::UpdateAnimation()
{
	currentFrame.x = animations[curAnim].w * animations[curAnim].frame;
	currentFrame.y = animations[curAnim].index * animations[curAnim].h;
	currentFrame.w = animations[curAnim].w;
	currentFrame.h = animations[curAnim].h;
	if (beginAnim > animations[curAnim].speed)
	{
		if (!rev)animations[curAnim].frame++;
		if (rev)animations[curAnim].frame--;
		beginAnim = 0;
	}
	beginAnim++;
	if (animations[curAnim].frame >= animations[curAnim].amount) { animations[curAnim].frame = 0; }
	if (animations[curAnim].frame <= 0)
	{
		if (nAb)
		{
			curAnim = newAnim;
			nAb = 0;
			rev = 0;
		}
		else
		{
			animations[curAnim].frame = 0;
		}
	}
}

void Entity::Destroy()
{
	std::cout << "I am the dead"<<std::endl;
}
