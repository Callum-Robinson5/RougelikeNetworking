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
        // Queue q
        World game;
        // receive
        // create receive thread(q)
        //need ID
        game.Run();
    }

    if(i == 's')
    {
        std::cout << "Is Server!" << std::endl;
        Network_Server server;
        std::thread(&Network_Server::accepter, &server).detach();
        server.send_tcp();

    }




/*

I use this code to make a monster chase after player, this works just fine:

float angle = atan2(player.y - monster.y, player.x -  monster.x);
 monster.move(cos(angle) * 0.5f,0);
 monster.move(0, sin(angle) * 0.5f);
*/




    return 0;
}
