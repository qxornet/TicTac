﻿#include "core.hpp"

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
      //  printf("\e[?25l");
    #endif
}

void Game::FpsLock()
{

}

void Game::createMap(int size)
{
    mapSize = size;

    map = new int*[size];
    for(int i = 0; i < size; i++)
    {
        map[i] = new int[size];
        for(int j = 0; j < size; j++)
            map[i][j] = 0;
    }

}

void Game::printMap()
{
    std::cout << "Y";
    for(int i = 0; i < mapSize; i++)
      std::cout << " _";

    std::cout << std::endl;

    for(int i = 0; i < mapSize; i++)
    {
        std::cout << i+1;

        for(int j = 0; j < mapSize; j++)
        {
            char symbol = getPlayersSymbol(map[i][j]);
            std::cout << "|" << symbol; 
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl;
}

char Game::getPlayersSymbol(int idx)
{
    switch (idx)
    {
    case 1: return 'X';
    case 2: return 'O';
    default: return '_';
    }
}

Game::~Game()
{
    for(int i = 0; i < mapSize; i++)
        delete map[i];

    delete[] map;
}