
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "RenderWindow.h"
#include "Entity.h"
#include "Player.h"

int main(int argc, char**argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        std::cout << "Init Error: " << SDL_GetError() << std::endl;
    }
    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "Image Init Error: " << SDL_GetError() << std::endl;
    }

    RenderWindow window("Azure", 1280, 720);

    SDL_Texture* charTex = window.LoadTexture("Assets/Characters/Sam_idle_sword_1.png");
    SDL_Texture* grass = window.LoadTexture("Assets/Tiles/ground_grass_1.png");

    std::vector<Entity> entities;
    entities.push_back(Entity(0, 0, 32, 32, grass));
    entities.push_back(Entity(30, 0, 32, 32, grass));
    entities.push_back(Entity(30, 30, 32, 32, grass));
    entities.push_back(Entity(30, 60, 32, 32, grass));

    Player player (10.f, 30.f, 64, 64, charTex);
    entities.push_back(player);
    bool gameRunning = true;

    SDL_Event event;
    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
        }

        window.Clear();
        for (Entity& e : entities)
        {
            window.Render(e);
        }
        //window.Render(player);
        window.Draw();
    }
    return 0;
}
