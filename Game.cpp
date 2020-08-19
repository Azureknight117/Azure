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
    SDL_Texture* pBeam = window.LoadTexture("Assets/Circlebeam.png");
    Player player(150.f, 60.f, 32, 32, charTex);
    Entity star(190.f, 110.f, 32, 32, starTex);
    entities.push_back(star);
    Projectile blast(180.f, 50.f, 8, 8, pBeam);
    projectiles.push_back(blast);
    SDL_Event event;
    while (gameRunning)
    {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();

        deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());
        window.Clear();

        Transform safe = player.transform;
        Input(event, player);
        player.Update(deltaTime);

        for (Entity& e : entities)
        {
            e.Update(deltaTime);
            window.Render(e);
            if (CheckCollision(e, player))
            {
                player.velocity.Zero();
                player.transform = safe;
                std::cout << "Collision!" << std::endl;
                break;
            }
        }
        for (Projectile& p : projectiles)
        {
            p.Update(deltaTime);
            window.Render(p);
        }
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

bool Game::CheckCollision(Entity a, Entity b)
{
    return(a.transform.x < b.transform.x + b.currentFrame.w &&
        a.transform.x + a.currentFrame.w > b.transform.x &&
        a.transform.y < b.transform.y + b.currentFrame.h &&
        a.transform.y + a.currentFrame.h > b.transform.y);
}

void Game::InitProjectile(Entity e, Projectile p)
{

}