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
    void Render(sf::RenderWindow& window);

protected:

private:

    sf::RectangleShape m_shape0{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape1{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape2{sf::Vector2f(25,25)};
    std::list<sf::RectangleShape> m_walls;
    std::list<sf::RectangleShape>::iterator it;
};

#endif // WALL_H
