#include "Receiver.h"
#include <cstring>
#include <cstdio>
#include <iostream>



void Receiver::recv_loop()
{
    char buffer[256];
    while(1);
    {
        std::memset(buffer, 0, 256);
        std::size_t received;
        sf::Socket::Status status = socket->receive(buffer, 256, received);
        if(status != sf::Socket::Done)
        {
            perror("Recieve");
            std::cerr << "Receive: " << status << std::endl;
            return;
        }
        if(isServer)
        {
            queue.push(std::string(buffer));
        }
    }
}
