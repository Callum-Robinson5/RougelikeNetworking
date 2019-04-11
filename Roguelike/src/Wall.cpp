#include "Wall.h"

Wall::Wall()
{
    //ctor
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





