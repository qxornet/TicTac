#include "core.hpp"

class Enemy : public Game
{
public:
    
    Enemy(Game* currGame);

    std::pair<int, int> minimax(MapField _map);
    std::vector< std::pair<int, int> > getAvailMoves(MapField _map);
    
private:

    Game* game;

    std::pair<int, int> choice;
};
