#include "Wall.h"

Wall::Wall()
{
    //ctor

    /*
    sf::RectangleShape m_shape0{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape1{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape2{sf::Vector2f(25,25)};
    m_shape0.setFillColor(sf::Color::Red);
    m_shape0.setPosition(sf::Vector2f(200,200));
    m_shape1.setFillColor(sf::Color::Blue);
    m_shape1.setPosition(sf::Vector2f(150,200));
    m_shape2.setFillColor(sf::Color::Yellow);
    m_shape2.setPosition(sf::Vector2f(100,200));



    m_walls.push_front(m_shape0);
    m_walls.push_front(m_shape1);
    m_walls.push_front(m_shape2); */

}

Wall::~Wall()
{
    //dtor
}


std::list<sf::RectangleShape> Wall::wallsList()
{
    return m_walls;
}

void Wall::wall_add(sf::RectangleShape rect)
{
    m_walls.push_front(rect);
}





