#include <iostream>

using namespace std;

#include "World.h"
#include "Network_Server.h"

int main()
{


    char i;
    std::cout << "Are You Client Or Server?" << std::endl;
    std::cout << "Type 'c' For Client Or 's' for Server" << std::endl;

    cin >> i;

    if(i == 'c')
    {
        std::cout << "Is Client!" << std::endl;
        World game;
        game.Run();
    }

    if(i == 's')
    {
        std::cout << "Is Server!" << std::endl;
        Network_Server server;
        server.accepter();
    }










    return 0;
}