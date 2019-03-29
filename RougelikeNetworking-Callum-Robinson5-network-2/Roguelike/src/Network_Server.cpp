#include "Network_Server.h"
#include "Receiver.h"
#include <iostream>
#include <cstring>
#include <thread>


Network_Server::Network_Server()
{
    //ctor
    m_ip = sf::IpAddress::getLocalAddress();
    std::thread(&Network_Server::accepter, this);
    //message_distrib();
}

Network_Server::~Network_Server()
{
    //dtor
}


void Network_Server::accepter()
{
    sf::Socket::Status status = m_listener.listen(4300);
    if(status != sf::Socket::Done)
    {
        std::cerr << "Listening Current Status: " << status << std::endl;
        return;
    }
    while(1)
    {
        sf::TcpSocket *socket = new sf::TcpSocket;
        status = m_listener.accept(*socket);
        if(status != sf::Socket::Done)
        {
            std::cerr << "Accept error: " << status << std::endl;
            return;
        }
        // push socket in a list of sockets
        {
        std::unique_lock<std::mutex> l(m);
        sockets.push_back(socket);
        }

        Receiver *receiver = new Receiver(socket, true, q);
        std::thread([receiver]{receiver->recv_loop();}).detach();

    }
}

void Network_Server::send_tcp(std::string)
{

}
