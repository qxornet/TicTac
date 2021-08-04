#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <chrono>
#include <ctime>
#include <map>

class Game
{

public:

    Game() = default;
    ~Game() = default;

public:

    virtual void Start(); // <- инициализация стартовых переменных
    virtual void Update(); // <- основная функция реализующая логику
    virtual void Exit(); // <- выход из программы
    virtual void Error(int code); // <- выход из программы, вывод сообщения об ошибке
    void FpsLock(); // ограничение на вывод кадров в секунду
    void Clean(); // очистка экрана

public:

    int exitCode = 0; // код выхода программы

protected:

    int fpsMax = 60; // максимум FPS
    std::map<int, std::string> errors; // сообщения об ошибках

private:

    std::chrono::system_clock::time_point deltaTime;
    std::chrono::system_clock::time_point lastTime;
};

#endif // CLIENT_HPP
