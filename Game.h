#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Entity.h"
#include "RenderWindow.h"
#include "Player.h"
#include "Projectile.h"

class Game
{
public:
	Game();
	~Game();

	void Loop();
	void Update();
	void Render();
	void Input(SDL_Event &event, Player &player);
	void Draw();

	bool CheckCollision(Entity a, Entity b);
	void InitProjectile(Entity e, Projectile p);

	double deltaTime = 0;
	Uint64 NOW, LAST = 0;
	bool gameRunning;
	int HEIGHT = 720;
	int WIDTH = 1280;
	
private:
	std::vector<Entity> entities;
	std::vector<Projectile> projectiles;
};

