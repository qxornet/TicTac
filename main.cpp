
#include <iostream>
#include "client.hpp"

int main()
{
    Game* client = new Client();
    
    client->Start();
    while(client->exitCode == 0)
    {
        client->Clean();
        client->Update();
        client->FpsLock();
    }

    delete client;

    return 0;
}
