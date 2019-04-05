#include "Receiver.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstring>
#include <stdio.h>


Receiver::Receiver(sf::TcpSocket* s, bool server, Queue<std::string>& q): socket(s), isServer(server), queue(q) {}

void Receiver::recv_loop()
{
    char buffer[256];
    while(1)
    {
        std::memset(buffer, 0, 256);
        std::size_t received;
        sf::Socket::Status status = socket->receive(buffer, 256, received);
        if(status != sf::Socket::Done)
        {
            perror("Receive");
            std::cerr << "Receive: " << status << std::endl;
            return;
        }

//        if(isServer)
//        {
            queue.push(std::string(buffer));
//            status = socket->send(buffer, received);
//            if(status != sf::Socket::Done)
//            {
//                std::cerr << "Send: " << status << std::endl;
//                return;
//            }
//        }
    }
}
