#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <chrono>
#include <ctime>
#include <map>
#include <vector>
#include <utility>

#ifdef WIN32
#include <windows.h>
#endif

#ifdef WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using MapField = std::vector< std::vector<int> >;
using Coordinate = std::pair<int, int>;

class Game
{

public:

    Game() = default;
    virtual ~Game();

public:

    virtual void Start(); // <- инициализация стартовых переменных
    virtual void Update(); // <- основная функция реализующая логику
    virtual void Exit(); // <- выход из программы
    virtual void Error(int code); // <- выход из программы, вывод сообщения об ошибке
    void FpsLock(); // ограничение на вывод кадров в секунду
    void Clean(); // очистка экрана

    void createMap();
    void createMap(int size);
    void printMap();

    char getPlayersSymbol(int idx);

public:

    int exitCode = 0; // код выхода программы

protected:

    //int** map;
    MapField map;

    int fpsMax = 60; // максимум FPS
    std::map<int, std::string> errors; // сообщения об ошибках

private:

    std::chrono::system_clock::time_point deltaTime;
    std::chrono::system_clock::time_point lastTime;
};

#endif // CORE_HPP
