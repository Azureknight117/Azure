
#include <iostream>
#include "Game.h"

int main(int argc, char**argv)
{
    Game newGame;
    newGame.Loop();
    return 0;
}


/*static double deltaTime;
bool gameRunning;
int HEIGHT = 720;
int WIDTH = 1280;

Player player(150, 32, 32, 37);
std::vector<Entity> entities;

void PlayerInput(SDL_Event &e)
{
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_QUIT:
            gameRunning = false;
            break;

        case SDL_KEYDOWN:
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                gameRunning = false;

                break;
            case SDLK_w:
                break;
            case SDLK_s:
                break;
            case SDLK_a:
                break;
            case SDLK_d:
                break;
            }
            break;
        }
        }
    }

    main

     if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        std::cout << "Init Error: " << SDL_GetError() << std::endl;
    }
    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "Image Init Error: " << SDL_GetError() << std::endl;
    }
    RenderWindow window("Azure", WIDTH, HEIGHT);

    SDL_Texture* grass = window.LoadTexture("Assets/Tiles/ground_grass_1.png");
    SDL_Texture* charTex = window.LoadTexture("Assets/Characters/Sword.png");

    player.SetTex(charTex);
    int idle = player.CreateAnim(0, 50, 37, 4, 1000);
    std::cout << "Anim state made" << std::endl;
    player.SetCurAnimation(idle);

entities.push_back(Entity(0, 0, 32, 32, grass));
entities.push_back(Entity(30, 0, 32, 32, grass));
entities.push_back(Entity(30, 30, 32, 32, grass));
entities.push_back(Entity(30, 60, 32, 32, grass));
entities.push_back(player);

gameRunning = true;
Uint64 NOW = SDL_GetPerformanceCounter();
Uint64 LAST = 0;

SDL_Event event;
while (gameRunning)
{
    PlayerInput(event);

    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();

    deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

    window.Clear();
    for (Entity& e : entities)
    {
        window.Render(e);
    }
    //player.UpdateAnimation();
    window.Render(player);
    window.Draw();
}
}
*/