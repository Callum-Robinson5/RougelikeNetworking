#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H


class Network_Client
{
public:
    Network_Client();
    virtual ~Network_Client();

    void connect();
    void send_tcp(std::string);
    void receive_tcp();

protected:

private:

    sf::TcpSocket socket;
    sf::IpAddress m_ip;

};

#endif // NETWORK_CLIENT_H
