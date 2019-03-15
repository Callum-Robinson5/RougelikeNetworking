#ifndef NETWORK_SERVER_H
#define NETWORK_SERVER_H
#include <SFML/Network.hpp>
#include <iostream>



class Network_Server
{
    public:
        Network_Server();
        virtual ~Network_Server();

        void accepter();
        void reciever();
        void send_tcp(std::string);

    protected:

    private:

    sf::IpAddress m_ip;
    sf::TcpListener m_listener;
    //sf::TcpSocket m_socket;


};

#endif // NETWORK_SERVER_H
