#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <locale>
#include "game.hpp"


#ifdef WIN32
#define CLEAR "clr"
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

    int fieldSize = 0;

};

#endif // CLIENT_H
