#include "client.hpp"

// инициализация переменных игры
void Client::Start()
{
    setlocale(LC_ALL, 0);
    std::cout << "Введите размер игрового поля: "; std::cin >> fieldSize;
    std::cout << std::endl;
    system(CLEAR);
}


// вывод необходимой информация, главный метод игры
void Client::Update()
{
    printField();
    std::cout << "Введите позицию (число с плавующей запятой) : ";
}

////////////////////////////////////////////////////////////////

void Client::printField()
{
    std::cout << "-------" << std::endl
              << "| | | |" << std::endl
              << "-------" << std::endl
              << "| | | |" << std::endl
              << "-------" << std::endl
              << "| | | |" << std::endl
              << "-------" << std::endl;
}
