#include "World.h"

World::World()
{
    //ctor
}

World::~World()
{
    //dtor
}


void World::Run()
{
    while (m_Window.isOpen())
    {
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_Window.close();
        }

        m_Player.Update();

        m_Window.clear();
        m_Player.Render(m_Window);
        m_Window.display();



    }
}
