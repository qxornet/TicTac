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
    #ifdef WIN32
        ShowCursor(false);
    #else
        printf("\e[?25l");
    #endif
}

void Game::FpsLock()
{

}

void Game::createMap(int size)
{
    mapSize = size;

    map = new bool*[size];
    for(int i = 0; i < size; i++)
        map[i] = new bool[size];
}

void Game::printMap()
{
    for(int i = 0; i < mapSize; i++)
      std::cout << "__";

    std::cout << std::endl;

    for(int i = 0; i < mapSize; i++)
    {
        for(int j = 0; j < mapSize; j++)
        {
            std::cout << "|_";
        }
        std::cout << "|" << std::endl;
    }
}

Game::~Game()
{
    for(int i = 0; i < mapSize; i++)
        delete map[i];

    delete[] map;
}