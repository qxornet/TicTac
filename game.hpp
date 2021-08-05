#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <chrono>
#include <ctime>
#include <map>

#ifdef WIN32
#include <windows.h>
#endif

class Game
{

public:

    Game() = default;
    ~Game();

public:

    virtual void Start(); // <- инициализация стартовых переменных
    virtual void Update(); // <- основная функция реализующая логику
    virtual void Exit(); // <- выход из программы
    virtual void Error(int code); // <- выход из программы, вывод сообщения об ошибке
    void FpsLock(); // ограничение на вывод кадров в секунду
    void Clean(); // очистка экрана

    void createMap(int size);
    void printMap();

public:

    int exitCode = 0; // код выхода программы

protected:

    bool** map;
    int mapSize = 3;

    int fpsMax = 60; // максимум FPS
    std::map<int, std::string> errors; // сообщения об ошибках

private:

    std::chrono::system_clock::time_point deltaTime;
    std::chrono::system_clock::time_point lastTime;
};

#endif // CLIENT_HPP
