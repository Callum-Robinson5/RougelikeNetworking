#include "World.h"
#include <iostream>     // std::cout
#include <sstream>      // std::ostringstream

World::World():
    m_Player(m_wall),
    m_Map(m_wall)
{
    //ctor
    //client.connect();
    for(int i = 0; i < numOfAI; i++)
    {
        m_Enemies.push_back(AI());
    }
}

World::~World()
{
    //dtor
}


void World::Run()
{
    unsigned short id = 1;
    sf::RenderWindow m_Window{sf::VideoMode(m_screenWidth, m_screenHeight), "T7087915 Roguelike"};

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



        for(int i = 0; i < numOfAI; i++)
        {
            if(m_Enemies[i].IsAlive == true)
            {
                m_Enemies[i].Update(m_Player.m_pos);
                for(int y= 0; y < m_Player.numBullets; y++)
                {
                    if(m_Enemies[i].m_Enemy.getGlobalBounds().intersects(m_Player.m_bullets[y].m_Projectile.getGlobalBounds()))
                    {
                        m_Enemies[i].IsAlive = false;
                    }
                }
            }
            if(m_Enemies[i].IsAlive == false)
            {
                m_Enemies[i].Spawn(m_screenHeight, m_screenWidth);
            }


        }



        //client.send_tcp();
        //std::ostringstream oss;
        //oss << id << ":" << m_Player.m_pos.x << ":" << m_Player.m_pos.y;;
        //client.qsend.push(oss.str());
        m_Window.clear();
        m_Player.Render(m_Window);
        m_Map.Render(m_Window);
        for(int i = 0; i < numOfAI; i++)
        {
            if(m_Enemies[i].IsAlive == true)
            {
                m_Enemies[i].Render(m_Window);
            }
        }
        m_Window.display();



    }
}
