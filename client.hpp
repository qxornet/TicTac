#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "game.hpp"

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

};

#endif // CLIENT_H
