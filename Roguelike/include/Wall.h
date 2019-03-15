#ifndef WALL_H
#define WALL_H
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>


class Wall
{
public:
    Wall();
    virtual ~Wall();

    std::list<sf::RectangleShape> wallsList();

    void wall_add(sf::RectangleShape rect);

protected:

private:


    std::list<sf::RectangleShape> m_walls;
    std::list<sf::RectangleShape>::iterator it;
};

#endif // WALL_H
