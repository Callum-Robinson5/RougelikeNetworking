#include "Network_Client.h"

Network_Client::Network_Client()
{
    //ctor
    m_ip = sf::IpAddress::getLocalAddress();
}

Network_Client::~Network_Client()
{
    //dtor
}


void Network_Client::connect()
{
    if(socket.connect(m_ip, 4300) != sf::Socket::Done)
    {
        std::cerr << "Connecting error: " << status << std::endl;
    }

}

void Network_Client::send_tcp(std::string s)
{
    sf::Socket::Status status = socket->send(s.c_str(), s.length());
    if (status != sf::Socket::Done)
    {
        std::cerr << "Sending error: " << status << std::endl;
    }
}

void Network_Client::receive_tcp()
{
    char buffer[256];
    std::size_t received;
    while(1)
    {
        std::memset(buffer, 0, 256);
        sf::Socket::Status status = socket.receive(buffer, 256, received);
        if (status != sf::Socket::Done)
        {
            std::cerr << "Receiving error: " << status << std::endl;
            return;
        }
        std::cout << buffer << std::endl;

        // push message on the queue
    }
}
