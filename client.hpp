#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <locale>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <variant>

#include "core.hpp"

class Client : public Game
{
public:
    Client() = default;
    ~Client() = default;

public:

    void Start() override;
    void Update() override;

private:

    void playerMove();
    void enemyMove();

    Coordinate setCoord();
    int makeMove(Coordinate coord);
    int checkState(MapField _map);
    int checkHoriz(MapField _map);
    int checkVert(MapField _map);
    int checkDiag(MapField _map);
    int checkInvDiag(MapField _map);

    std::variant<Coordinate, int> minimax(MapField _map);
    std::vector< Coordinate > getAvailMoves(MapField _map);

private:

    int fieldCount = 0;
    int blocksCount = 0;
    int allowBlockCount = 0;

    bool activeTurn; // 0 - enemy, 1 - player

    int player, enemy; // indicators on field (1 or 2)

    int playerEnableForWin = 0;
    int enemyEnableForWin = 0;

    int winCode = 0;

    Coordinate choice;
};

#endif // CLIENT_H
