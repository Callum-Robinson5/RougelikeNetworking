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
        void Level(int x);


    private:

    Wall &m_wall;

};

#endif // MAP_H
