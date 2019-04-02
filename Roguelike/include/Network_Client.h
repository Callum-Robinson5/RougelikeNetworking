#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H
#include <SFML/Network.hpp>
#include <iostream>
#include "Queue.h"
#include "Receiver.h"



class Network_Client
{
public:
    Network_Client();
    virtual ~Network_Client();

    void connect();
    void send_tcp();
    void receive_tcp();

protected:

private:

    int port;
    sf::TcpSocket socket;
    sf::IpAddress m_ip;
    Queue<std::string> q;
    std::mutex m;

};

#endif // NETWORK_CLIENT_H
