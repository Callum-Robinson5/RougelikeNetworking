#include <iostream>

using namespace std;

#include "World.h"
#include "Network_Server.h"

int difficulty();

int main()
{


    char i;
    std::cout << "Are You Client Or Server?" << std::endl;
    std::cout << "Type 'c' For Client Or 's' for Server" << std::endl;

    std::cin >> i;

    if(i == 'c')
    {
        std::cout << "Is Client!" << std::endl;
        int x = difficulty();

        World game;
        game.Run(x);
    }

    if(i == 's')
    {
        std::cout << "Is Server!" << std::endl;
        Network_Server server;
        std::thread(&Network_Server::accepter, &server).detach();
        server.send_tcp();

    }

    return 0;
}

int difficulty()
{
        int j;
        std::cout << "Select Difficulty 1 or 2" << std::endl;
        std::cin >> j;
        if(j != 1)
        {
        if(j != 2)
        {
        std::cout << "Select Difficulty 1 or 2" << std::endl;
        std::cin >> j;
        }
        }
}
