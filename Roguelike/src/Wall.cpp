#include "Wall.h"

Wall::Wall()
{
    //ctor
    m_shape0.setFillColor(sf::Color::Red);
    m_shape0.setPosition(sf::Vector2f(200,200));
    m_shape1.setFillColor(sf::Color::Blue);
    m_shape1.setPosition(sf::Vector2f(150,200));
    m_shape2.setFillColor(sf::Color::Yellow);
    m_shape2.setPosition(sf::Vector2f(100,200));



    m_walls.push_front(m_shape0);
    m_walls.push_front(m_shape1);
    m_walls.push_front(m_shape2);

}

Wall::~Wall()
{
    //dtor
}


std::list<sf::RectangleShape> Wall::wallsList()
{

    int i = 0;
//    for(it = m_walls.begin(); it != m_walls.end(); it++)
//    {
//
//        i++;
//        std::cout << i << std::endl;
//    }
    return m_walls;
}






void Wall::Render(sf::RenderWindow& window)
{
    //for(std::list<sf::RectangleShape>::iterator it = m_walls.begin(); it != m_walls.end(); ++it)
    //{
    //window.draw(*it);
    //}
}
