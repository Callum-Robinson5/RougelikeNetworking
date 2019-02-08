#include "Map.h"

Map::Map()
{
    m_test.setFillColor(sf::Color::Red);
    m_test.setPosition(sf::Vector2f(200,200));
    //ctor
}

Map::~Map()
{
    //dtor
}


void Map::Render(sf::RenderWindow& window)
{
    window.draw(m_test);
}
