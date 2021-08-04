#include "game.hpp"

void Game::Start()
{

}

void Game::Update()
{

}

void Game::Exit()
{
    exitCode = 1;
}

void Game::Error(int code)
{
    exitCode = code;
}

void Game::Clean()
{
    printf("\033[%d;%dH", 0, 0);
    printf("\e[?25l");
}

void FpsLock()
{

}
