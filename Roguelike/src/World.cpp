#include "World.h"
#include <iostream>     // std::cout
#include <sstream>      // std::ostringstream

World::World():
    m_Player(m_wall),
    m_Map(m_wall)
{
    //ctor
    //client.connect();
}

World::~World()
{
    //dtor
}


void World::Run()
{
    unsigned short id = 1;


    while (m_Window.isOpen())
    {
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_Window.close();
        }

        m_Player.Update();
        m_Player.shoot(m_Window);
        //client.send_tcp();
        //std::ostringstream oss;
        //oss << id << ":" << m_Player.m_pos.x << ":" << m_Player.m_pos.y;;
        //client.qsend.push(oss.str());
        m_Window.clear();
        m_Player.Render(m_Window);
        m_Map.Render(m_Window);
        m_Window.display();



    }
}
