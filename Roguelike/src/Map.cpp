#include "Map.h"

Map::Map(Wall &wall):
    m_wall(wall)
{


    sf::RectangleShape m_shape0{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape1{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape2{sf::Vector2f(25,25)};
    m_shape0.setFillColor(sf::Color::Red);
    m_shape0.setPosition(sf::Vector2f(200,200));
    m_shape1.setFillColor(sf::Color::Blue);
    m_shape1.setPosition(sf::Vector2f(150,200));
    m_shape2.setFillColor(sf::Color::Yellow);
    m_shape2.setPosition(sf::Vector2f(100,200));



    m_wall.wall_add(m_shape0);
    m_wall.wall_add(m_shape1);
    m_wall.wall_add(m_shape2);
    //wall.wallsList().push_back(m_shape0);
    //wall.wallsList().push_back(m_shape1);
    //wall.wallsList().push_back(m_shape2);


    //ctor
}

Map::~Map()
{
    //dtor
}


void Map::Render(sf::RenderWindow& window)
{
    for(auto const& it : m_wall.wallsList())
    {
        window.draw(it);
    }
}

void Map::Level(int x)
{

}
