#ifndef WORLD_H
#define WORLD_H

#include "Map.h"
#include "Wall.h"
#include "Network_Client.h"


class World
{
    public:
        World();
        virtual ~World();

        void Run();

    protected:

    private:

    class Network_Client client;

    int m_screenWidth{1280};
    int m_screenHeight{720};
    Wall m_wall;
    Player m_Player;
    Map m_Map;
    sf::RenderWindow m_Window{sf::VideoMode(m_screenWidth, m_screenHeight), "T7087915 Roguelike"};
};

#endif // WORLD_H
