#ifndef NETWORK_SERVER_H
#define NETWORK_SERVER_H
#include <SFML/Network.hpp>
#include <iostream>
#include "Queue.h"
#include <list>
#include <mutex>


class Network_Server
{
    public:
        Network_Server();
        virtual ~Network_Server();

        void accepter();
        void send_tcp(std::string);

    protected:

    private:

    sf::IpAddress m_ip;
    sf::TcpListener m_listener;
    Queue<std::string> q;
    std::list<sf::TcpSocket*> sockets;
    std::mutex m;


};

#endif // NETWORK_SERVER_H
