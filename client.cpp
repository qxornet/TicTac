#include "client.hpp"

void Client::Start()
{
    // GOTO: инициализация переменных игры
}

void Client::Update()
{
    // GOTO: вывод необходимой информация, главный метод игры
    printField();
    std::cout << "Please enter x position: ";
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
