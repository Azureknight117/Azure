#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RenderWindow.h"
#include "Entity.h"

RenderWindow::RenderWindow(const char* title, int w, int h)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

RenderWindow::~RenderWindow()
{
	SDL_DestroyWindow(window);
}

SDL_Texture* RenderWindow::LoadTexture(const char* filePath)
{
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(renderer, filePath);
	if (texture == nullptr)
	{
		std::cout << "Failed to Load texture. Error: " << SDL_GetError() << std::endl;
	}
	return texture;
}

void RenderWindow::Clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::Render(Entity& entity)
{
	SDL_Rect src;
	SDL_Rect dst;

	src.x = entity.currentFrame.x;
	src.y = entity.currentFrame.y;
	src.w = entity.currentFrame.w;
	src.h = entity.currentFrame.h;

	dst.x = entity.transform.x * 4;
	dst.y = entity.transform.y * 4;
	dst.w = entity.currentFrame.w * 4;
	dst.h = entity.currentFrame.h * 4;

	SDL_RenderCopy(renderer, entity.texture, &src, &dst);
}

void RenderWindow::Draw()
{
	SDL_RenderPresent(renderer);
}