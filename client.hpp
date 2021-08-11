#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <locale>
#include <cmath>
#include <iomanip>

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

    void setCoord();
    int makeMove(int y, int x );
    int enemyMove();
    int checkState();

private:

    int fieldCount = 0;
    int blocksCount = 0;
    int allowBlockCount = 0;

    double xCoord;
    double yCoord;
    
};

#endif // CLIENT_H
