#include "client.hpp"

// инициализация переменных игры
void Client::Start()
{
    setlocale(LC_ALL, 0);
    std::cout << "Введите размер игрового поля: "; 
        std::cin >> fieldCount;
    std::cout << std::endl;
    createMap(fieldCount);
    system(CLEAR);
}


// вывод необходимой информация, главный метод игры
void Client::Update()
{
    printMap();
    std::cout << "Введите позицию (число с плавующей запятой) : ";
}

////////////////////////////////////////////////////////////////

