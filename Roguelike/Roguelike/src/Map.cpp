#include "Map.h"

Map::Map(Wall &wall):
    m_wall(wall)
{

    //bottom wall
    sf::RectangleShape m_shape0{sf::Vector2f(1000,-100)};
    m_shape0.setFillColor(sf::Color::Red);
    m_shape0.setPosition(sf::Vector2f(-50,50));

    //left wall
    sf::RectangleShape m_shape1{sf::Vector2f(-100,-1000)};
    m_shape1.setFillColor(sf::Color::Red);
    m_shape1.setPosition(sf::Vector2f(-50,50));

    //right wall
    sf::RectangleShape m_shape2{sf::Vector2f(100,-1000)}; //right wall
    m_shape2.setFillColor(sf::Color::Red);
    m_shape2.setPosition(sf::Vector2f(940,50));

    //top wall
    sf::RectangleShape m_shape3{sf::Vector2f(1000,-100)};
    m_shape3.setFillColor(sf::Color::Red);
    m_shape3.setPosition(sf::Vector2f(-50,-940));




    //adds all walls to wall list
    m_wall.wall_add(m_shape0);
    m_wall.wall_add(m_shape1);
    m_wall.wall_add(m_shape2);
    m_wall.wall_add(m_shape3);



    m_shape4.setFillColor(sf::Color::Red);
    m_shape5.setFillColor(sf::Color::Red);
    m_shape6.setFillColor(sf::Color::Red);
    m_shape7.setFillColor(sf::Color::Red);
    m_shape8.setFillColor(sf::Color::Red);





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

void Map::Spawn()
{

    for(int i = 0; i < 5; i++)
    {
        int x = rand()%800;
        int y = 0 - rand()%800;

        if(x < 50)
        {
            x += 50;
        }
        switch(i)
        {
        case 0 :
            m_shape4.setPosition(sf::Vector2f(400, -400));
            m_wall.wall_add(m_shape4);
            std::cout << x << y << std::endl;
            break;
        case 1 :
            m_shape5.setPosition(sf::Vector2f(x, y));
            m_wall.wall_add(m_shape5);


            break;
        case 2 :
            m_shape6.setPosition(sf::Vector2f(x, y));
             m_wall.wall_add(m_shape6);


            break;
        case 3 :
            m_shape7.setPosition(sf::Vector2f(x, y));
             m_wall.wall_add(m_shape7);


            break;
        case 4 :
            m_shape8.setPosition(sf::Vector2f(x, y));
            m_wall.wall_add(m_shape8);

            break;
        }
    }
}
