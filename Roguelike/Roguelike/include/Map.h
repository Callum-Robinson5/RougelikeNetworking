#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Player.h"



class Map
{
    public:
        Map(Wall &wall);
        virtual ~Map();

        void Render(sf::RenderWindow& window);
        void Spawn();


    private:


    //random spawning walls
    sf::RectangleShape m_shape4{sf::Vector2f(50, 200)};

    sf::RectangleShape m_shape5{sf::Vector2f(50, 250)};

    sf::RectangleShape m_shape6{sf::Vector2f(50, 300)};

    sf::RectangleShape m_shape7{sf::Vector2f(200, 50)};

    sf::RectangleShape m_shape8{sf::Vector2f(250, 50)};

    sf::RectangleShape m_shape9{sf::Vector2f(300, 50)};
    Wall &m_wall;

};

#endif // MAP_H
