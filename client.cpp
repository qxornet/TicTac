#include "client.hpp"

void Client::Start()
{
    setlocale(LC_ALL, 0);
    srand( (unsigned)time(NULL) );
    
    activeTurn = false;
    player = 1 + rand() % 2;
    if(player == 1) enemy = 2;
    else enemy = 1;

    std::cout <<"Введите размер игрового поля: "; 
        std::cin >> fieldCount;
    std::cout << std::endl;

    createMap(fieldCount);
    blocksCount = fieldCount * fieldCount;
    system(CLEAR);

    if(player == 1) activeTurn = true;
}

void Client::Update()
{
    if(allowBlockCount >= blocksCount)
    {
        system(CLEAR);
        std::cout << "GAME OVER" << std::endl;
        return Exit();
    }

    std::cout << "Вы играете за: " << this->getPlayersSymbol(player) << std::endl; 
    printMap();

    if(activeTurn) playerMove();
    else this->enemyMove();

    if(this->checkState(map) != 0) 
    {
        system(CLEAR);
        if(winCode == player) std::cout << "PLAYER WIN" << std::endl;
        if(winCode == enemy) std::cout << "ENEMY WIN" << std::endl;
        return Exit();
    }
    system(CLEAR);
}

//------------------------------------------------------------------

int Client::makeMove(Coordinate coord)
{
    if(coord.first > map.size() || coord.second > map.size()) 
    {
        std::cout << "Неверная координата, повторите ещё. <Press Enter>";
        return 1;
    }

    if(map[coord.first-1][coord.second-1] != 0)
    {
        std::cout << "Эта клетка уже занята. Повторите ещё. <Press Enter> ";
        return 1;
    }

    map[coord.first-1][coord.second-1] = player;
    allowBlockCount++;

    return 0;
}

Coordinate  Client::setCoord()
{
    double value = 0.0;
    std::cin >> value; std::cout << std::endl;
    double x = 0, y = 0;
    x = (std::modf(value, &y) * 10.0) + 0.1; 

    int xCoord = static_cast<int>(x),
        yCoord = static_cast<int>(y);

    return std::make_pair(yCoord, xCoord);
}

void Client::playerMove()
{
    std::cout << "Введите позицию (формат: y.x): ";

    if(this->makeMove(this->setCoord()) != 0) 
        std::getchar();

    activeTurn = false;
}

void Client::enemyMove()
{
    minimax(map);
    map[choice.first-1][choice.second-1] = enemy;
    activeTurn = true;

/*     while(allowBlockCount < blocksCount)
    {
        int x = 1 + rand() % map.size();
        int y = 1 + rand() % map.size();

        if(map[y-1][x-1] != 0) continue;

        map[y-1][x-1] = enemy;
        allowBlockCount++;
        break;
    } 
 */
}

int Client::checkState(MapField _map)
{
    if((winCode = checkHoriz(_map)) != 0) return winCode;
    if((winCode = checkVert(_map)) != 0) return winCode;
    if((winCode = checkDiag(_map)) != 0) return winCode;
    if((winCode = checkInvDiag(_map)) != 0) return winCode;

    return 0;
}

int Client::checkHoriz(MapField _map)
{
    int playerEnableForWin = 0;
    int enemyEnableForWin = 0;

    for(int i = 0; i < map.size(); i++)
    {
        playerEnableForWin = 0;
        enemyEnableForWin = 0;
        
        for(int j = 0; j < map.size(); j++)
        {
            if(map[i][j] == player) playerEnableForWin += 1;
            if(map[i][j] == enemy) enemyEnableForWin += 1;
        }

        if(playerEnableForWin == map.size()) return player;
        if(enemyEnableForWin == map.size()) return enemy;
    }

    return 0;
}

int Client::checkVert(MapField _map)
{
    int playerEnableForWin = 0;
    int enemyEnableForWin = 0;

    for(int i = 0; i < map.size(); i++)
    {
        playerEnableForWin = 0;
        enemyEnableForWin = 0;

        for(int j = 0; j < map.size(); j++)
        {
            if(map[j][i] == player) playerEnableForWin += 1;
            if(map[j][i] == enemy) enemyEnableForWin += 1;
        }

        if(playerEnableForWin == map.size()) return player;
        if(enemyEnableForWin == map.size()) return enemy;
    }

    return 0;    
}

int Client::checkDiag(MapField _map)
{
    int playerEnableForWin = 0;
    int enemyEnableForWin = 0;

    for(int i = 0; i < map.size(); i++)
    {
        if(map[i][i] == player) playerEnableForWin += 1;
        if(map[i][i] == enemy) enemyEnableForWin += 1;
    }
    
    if(playerEnableForWin == map.size()) return player;
    if(enemyEnableForWin == map.size()) return enemy;

    return 0;
}

int Client::checkInvDiag(MapField _map)
{
    int playerEnableForWin = 0;
    int enemyEnableForWin = 0;

    for(int i = 0, j = map.size()-1; i < map.size(); i++, j--)
    {
        if(map[i][j] == player) playerEnableForWin += 1;
        if(map[i][j] == enemy) enemyEnableForWin += 1;
    }
    
    if(playerEnableForWin == map.size()) return player;
    if(enemyEnableForWin == map.size()) return enemy;

    return 0;
}

std::vector< Coordinate > Client::getAvailMoves(MapField _map)
{
    std::vector< Coordinate > moves;
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

std::variant<Coordinate, int> Client::minimax(MapField _map)
{
    checkState(_map);

    std::vector<int> scores;
    std::vector<Coordinate> moves;

    auto mapMoves = this->getAvailMoves(_map);
    if(mapMoves.size() <= 0) return 0;
    
    for(auto& move : mapMoves) 
    {
        MapField buffMap = _map;
        map[move.first][move.second] = enemy;
        scores.push_back(std::get<int>(minimax(buffMap)));
        moves.push_back(move);
    }  

    if(player == 1)
    {
        auto iter = std::max_element(scores.begin(), scores.end());
        choice = moves[std::distance(scores.begin(), iter)];
        return *iter;
    }
    else
    {
        auto iter = std::min_element(scores.begin(), scores.end());
        choice = moves[std::distance(scores.begin(), iter)];
        return *iter;
    }


    return std::make_pair(0,0);
}