#ifndef RECEIVER_H
#define RECEIVER_H
#include <SFML/Network.hpp>
#include "Queue.h"

class Receiver
{
    public:
        Receiver(sf::TcpSocket* s, bool server,Queue<std::string>& queue);
        void recv_loop();

    protected:

    private:
    sf::TcpSocket* socket;
    bool isServer = false;
    Queue<std::string> &queue; //new
};

#endif // RECEIVER_H
