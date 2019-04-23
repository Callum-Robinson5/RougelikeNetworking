#include "Network_Client.h"
#include <cstring>

Network_Client::Network_Client()
{
    //ctor
    m_ip = sf::IpAddress::getLocalAddress();
    port = 63001;
}

Network_Client::~Network_Client()
{
    //dtor
}


void Network_Client::connect()
{
    sf::Socket::Status status = socket.connect(m_ip, port);
    if(status != sf::Socket::Done)
    {
        std::cerr << "Connecting error: " << status << std::endl;
    }

}

void Network_Client::send_tcp()
{
    while(1)
    {
        std::string s = qsend.pop(); //blocking
        std::cout << "Main read: '" << s << "'\n" << std::endl;
        {
            std::unique_lock<std::mutex> l(m);
            sf::Socket::Status status = socket.send(s.c_str(), s.size());
            if(status != sf::Socket::Done)
            {
                std::cout << "Sending Failed: " << status << std::endl;
            }
        }
    }
}

void Network_Client::receive_tcp()
{
    char buffer[256];
    while(1)
    {
        std::memset(buffer, 0, 256);
        std::size_t received;
        sf::Socket::Status status = socket.receive(buffer, 256, received);
        if(status != sf::Socket::Done)
        {
            perror("Receive");
            std::cerr << "Receive: " << status << std::endl;
            return;
        }
        qrec.push(std::string(buffer));
    }
}

