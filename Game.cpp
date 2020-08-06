#include "Game.h"

Game::Game()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        std::cout << "Init Error: " << SDL_GetError() << std::endl;
    }
    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "Image Init Error: " << SDL_GetError() << std::endl;
    }
    gameRunning = true;
    
}
Game::~Game()
{

}

void Game::Loop()
{
    RenderWindow window("Azure", WIDTH, HEIGHT);
    SDL_Texture* charTex = window.LoadTexture("Assets/Characters/Sword.png");
    SDL_Texture* starTex = window.LoadTexture("Assets/Characters/Star(Enemy).png");
    Player player(150, 60, 32, 32, charTex);
    Entity star(150.f, 110.f, 32, 32, starTex);
    entities.push_back(star);

    SDL_Event event;
    while (gameRunning)
    {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();

        deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());
        window.Clear();
        for (Entity& e : entities)
        {
            //e.Update(deltaTime);
            window.Render(e);
        }
        Input(event, player);
        player.Update(deltaTime);
        window.Render(player);
        window.Draw();
    }
}

void Game::Update()
{

}

void Game::Render()
{

}
void Game::Draw()
{

}

void Game::Input(SDL_Event &event, Player &player)
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            gameRunning = false;
            break;

        case SDL_KEYDOWN:
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                gameRunning = false;
                break;
            case SDLK_w:
                player.velocity.y = -2;
                player.rotation = 0;
                break;
            case SDLK_s:
                player.velocity.y = 2;
                player.rotation = 180;
                break;
            case SDLK_a:
                player.velocity.x = -2;
                player.rotation = -90;
                break;
            case SDLK_d:
                player.velocity.x = 2;
                player.rotation = 90;
                break;
            }
            break;
        }
        case SDL_KEYUP:
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_w:
                player.velocity.y = 0;
                break;
            case SDLK_s:
                player.velocity.y = 0;
                break;
            case SDLK_a:
                player.velocity.x = 0;
                break;
            case SDLK_d:
                player.velocity.x = 0;
                break;
            }
            break;
        }
        }
    }
}

bool Game::Collision(Entity a, Entity b)
{
    return false;
}