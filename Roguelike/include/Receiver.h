#ifndef RECEIVER_H
#define RECEIVER_H
#include <SFML/Network.hpp>
#include "Queue.h"


class Receiver
{
    public:
        Receiver(sf::TcpSocket* s, bool server, Queue<std::string>& q);
        void recv_loop();

    protected:

    private:
    sf::TcpSocket* socket;
    bool isServer;
    Queue<std::string> &queue;
};

#endif // RECEIVER_H
