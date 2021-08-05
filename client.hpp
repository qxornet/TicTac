#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <locale>
#include "game.hpp"


#ifdef WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

class Client : public Game
{
public:
    Client() = default;
    ~Client() = default;

public:

    void Start() override;
    void Update() override;

private:

    void printField();

private:

    int fieldCount = 0;
    
};

#endif // CLIENT_H
