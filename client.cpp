#include "client.hpp"

void Client::Start()
{
    setlocale(LC_ALL, 0);
    srand( (unsigned)time(NULL) );

    std::cout << "Введите размер игрового поля: "; 
        std::cin >> fieldCount;
    std::cout << std::endl;

    createMap(fieldCount);
    blocksCount = fieldCount * fieldCount;
    system(CLEAR);
}

void Client::Update()
{
    if(allowBlockCount >= blocksCount)
    {
        system(CLEAR);
        std::cout << "GAME OVER" << std::endl;
        return Exit();
    }
    
    printMap();
    std::cout << "Введите позицию (формат: y.x): ";

    this->setCoord();
    if(this->makeMove(yCoord, xCoord) != 0)
    { 
        std::getchar();
        return;
    }
    this->enemyMove();
    this->checkState();
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

    map[y-1][x-1] = 1;
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
    int max,min;
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

    map[max][min] = 2;

/*     while(allowBlockCount < blocksCount)
    {
        int x = 1 + rand() % mapSize;
        int y = 1 + rand() % mapSize;

        if(map[y-1][x-1] != 0) continue;

        map[y-1][x-1] = 2;
        allowBlockCount++;
        break;
    } */
}

int Client::checkState()
{

}
