#include "client.hpp"

void Client::Start()
{
    setlocale(LC_ALL, 0);
    srand( (unsigned)time(NULL) );
    
    player = 1 + rand() % 2;
    if(player == 1) enemy = 2;
    else enemy = 1;

    std::cout << player << " Введите размер игрового поля: "; 
        std::cin >> fieldCount;
    std::cout << std::endl;

    createMap(fieldCount);
    blocksCount = fieldCount * fieldCount;
    system(CLEAR);

    if(player == 1) this->enemyMove();
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
    std::cout << "Введите позицию (формат: y.x): ";

    this->setCoord();
    if(this->makeMove(yCoord, xCoord) != 0)
    { 
        std::getchar();
        return;
    }
    this->enemyMove();
    if(this->checkState() != 0) 
    {
        system(CLEAR);
        if(winCode == player) std::cout << "PLAYER WIN" << std::endl;
        if(winCode == enemy) std::cout << "ENEMY WIN" << std::endl;
        return Exit();
    }
    system(CLEAR);
}

//------------------------------------------------------------------

int Client::makeMove(int y, int x)
{
    if(x > mapSize || y > mapSize) 
    {
        std::cout << "Неверная координата, повторите ещё. <Press Enter>";
        return 1;
    }

    if(map[y-1][x-1] != 0)
    {
        std::cout << "Эта клетка уже занята . Повторите ещё. <Press Enter> ";
        return 1;
    }

    map[y-1][x-1] = player;
    allowBlockCount++;

    return 0;
}

void Client::setCoord()
{
    double value = 0.0;
    std::cin >> value; std::cout << std::endl;
    double x = 0, y = 0;
    x = (std::modf(value, &y) * 10.0) + 0.1; 

    xCoord = static_cast<int>(x);
    yCoord = static_cast<int>(y);
}

int Client::enemyMove()
{
/*     int max,min;
    for(int i = 0; i < fieldCount; i++)
    {
        min = map[i][0];
        for(int j = 1; j < fieldCount; j++)
        {
            if(map[i][j] != 0) continue;
            if(map[i][j]<min) min=map[i][j];
        }
        if(i==0) max=min;
        if(max<min) max=min;
    }

    map[max][min] = 2; */

    while(allowBlockCount < blocksCount)
    {
        int x = 1 + rand() % mapSize;
        int y = 1 + rand() % mapSize;

        if(map[y-1][x-1] != 0) continue;

        map[y-1][x-1] = enemy;
        allowBlockCount++;
        break;
    } 
}

int Client::checkState()
{
    if((winCode = checkHoriz()) != 0) return winCode;
    if((winCode = checkVert()) != 0) return winCode;
    if((winCode = checkDiag()) != 0) return winCode;
    if((winCode = checkInvDiag()) != 0) return winCode;

    return 0;
}

int Client::checkHoriz()
{
    int playerEnableForWin = 0;
    int enemyEnableForWin = 0;

    for(int i = 0; i < mapSize; i++)
    {
        playerEnableForWin = 0;
        enemyEnableForWin = 0;
        
        for(int j = 0; j < mapSize; j++)
        {
            if(map[i][j] == player) playerEnableForWin += 1;
            if(map[i][j] == enemy) enemyEnableForWin += 1;
        }

        if(playerEnableForWin == mapSize) return player;
        if(enemyEnableForWin == mapSize) return enemy;
    }

    return 0;
}

int Client::checkVert()
{
    int playerEnableForWin = 0;
    int enemyEnableForWin = 0;

    for(int i = 0; i < mapSize; i++)
    {
        playerEnableForWin = 0;
        enemyEnableForWin = 0;

        for(int j = 0; j < mapSize; j++)
        {
            if(map[j][i] == player) playerEnableForWin += 1;
            if(map[j][i] == enemy) enemyEnableForWin += 1;
        }

        if(playerEnableForWin == mapSize) return player;
        if(enemyEnableForWin == mapSize) return enemy;
    }

    return 0;    
}

int Client::checkDiag()
{
    int playerEnableForWin = 0;
    int enemyEnableForWin = 0;

    for(int i = 0; i < mapSize; i++)
    {
        if(map[i][i] == player) playerEnableForWin += 1;
        if(map[i][i] == enemy) enemyEnableForWin += 1;
    }
    
    if(playerEnableForWin == mapSize) return player;
    if(enemyEnableForWin == mapSize) return enemy;

    return 0;
}

int Client::checkInvDiag()
{
    int playerEnableForWin = 0;
    int enemyEnableForWin = 0;

    for(int i = 0, j = mapSize-1; i < mapSize; i++, j--)
    {
        if(map[i][j] == player) playerEnableForWin += 1;
        if(map[i][j] == enemy) enemyEnableForWin += 1;
    }
    
    if(playerEnableForWin == mapSize) return player;
    if(enemyEnableForWin == mapSize) return enemy;

    return 0;
}