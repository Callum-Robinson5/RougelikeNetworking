#include "Network_Server.h"
#include <iostream>
#include <cstring>

Network_Server::Network_Server()
{
    //ctor
    m_ip = sf::IpAddress::getLocalAddress();
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
        char buffer[256];
        std::memset(buffer, 0, 256);
        std::size_t received;
        status = socket->receive(buffer, 256, received);
        if(status != sf::Socket::Done)
        {
            std::cerr << "Recv error: " << status << std::endl;
            return;
        }
        status = socket->send(buffer, sizeof(buffer));
        if(status != sf::Socket::Done)
        {
            std::cerr << "Send error: " << status << std::endl;
            return;
        }

    }
}
void Network_Server::reciever()
{

}
void Network_Server::send_tcp(std::string)
{

}
