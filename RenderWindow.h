#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"

class RenderWindow
{
public:
	RenderWindow(const char* title, int w, int h);
	~RenderWindow();
	SDL_Texture* LoadTexture(const char* filePath);
	void Clear();
	void Render(Entity& entity);
	void Draw();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

