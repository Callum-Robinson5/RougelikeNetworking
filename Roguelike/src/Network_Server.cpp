#include "Network_Server.h"
#include "Receiver.h"
#include <iostream>
#include <cstring>
#include <thread>


Network_Server::Network_Server()
{
    //ctor
    m_ip = sf::IpAddress::getLocalAddress();
    port = 63001;
}

Network_Server::~Network_Server()
{
    //dtor
}


void Network_Server::accepter()
{
    sf::Socket::Status status = m_listener.listen(port);
    if(status != sf::Socket::Done)
    {
        std::cerr << "Listening Current Status: " << status << std::endl;
        return;
    }
    while(1)
    {
        sf::TcpSocket *socket = new sf::TcpSocket;
        status = m_listener.accept(*socket);
        {
            // push socket in a list of sockets
            std::unique_lock<std::mutex> l(m);
            sockets.push_back(socket);
        }
        if(status != sf::Socket::Done)
        {
            std::cerr << "Accept error: " << status << std::endl;
            return;
        }


        Receiver *receiver = new Receiver(socket, true, q);
        std::thread([receiver] {receiver->recv_loop();}).detach();

    }
}

void Network_Server::send_tcp()
{
    while(1)
    {
        std::string s = q.pop(); //blocking
        std::cout << "Main read: " << s << std::endl;
        {
            std::unique_lock<std::mutex> l(m);
            for(auto socket : sockets)
            {
                sf::Socket::Status status = socket->send(s.c_str(), s.size());
                if(status != sf::Socket::Done)
                {
                    std::cout << "Sending Failed: " << status << std::endl;
                }
            }
        }
    }
}
