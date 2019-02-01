#ifndef WORLD_H
#define WORLD_H
#include "Player.h"
#include <SFML/Graphics.hpp>

class World
{
    public:
        World();
        virtual ~World();

        void Run();

    protected:

    private:


    int m_screenWidth{1280};
    int m_screenHeight{720};
    Player m_Player;
    sf::RenderWindow m_Window{sf::VideoMode(m_screenWidth, m_screenHeight), "T7087915 Roguelike"};
};

#endif // WORLD_H
