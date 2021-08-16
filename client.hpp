#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <locale>
#include <cmath>
#include <iomanip>

#include "core.hpp"

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
    int checkHoriz();
    int checkVert();
    int checkDiag();
    int checkInvDiag();

private:

    int fieldCount = 0;
    int blocksCount = 0;
    int allowBlockCount = 0;

    double xCoord;
    double yCoord;

    int player, enemy; // indicators on field (1 or 2)
    int playerEnableForWin = 0;
    int enemyEnableForWin = 0;

    int winCode = 0;
};

#endif // CLIENT_H
