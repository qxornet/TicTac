#include "enemy.hpp"

Enemy::Enemy(Game* currGame) :
    game(currGame)
{

}

std::vector< std::pair<int, int> > Enemy::getAvailMoves(MapField _map)
{
    std::vector< std::pair<int, int> > moves;
    for(int i = 0; i < _map.size(); ++i)
    {
        for(int j = 0; j < _map.size(); ++j)
        {
            if(map[i][j] == 0)
            moves.push_back(std::make_pair(i,j));
        }
    }

    return moves;
}

std::pair<int, int> Enemy::minimax(MapField _map)
{
    std::vector<int> scores;
    std::vector<int> moves;

    for(auto& move : this->getAvailMoves(_map))   


    return std::make_pair(0,0);
}