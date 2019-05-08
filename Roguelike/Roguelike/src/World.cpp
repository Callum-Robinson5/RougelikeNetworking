#include "World.h"
#include <iostream>     // std::cout
#include <sstream>      // std::ostringstream
#include <stdlib.h>

World::World():
    m_Player(m_wall),
    m_Map(m_wall)
{
    //ctor
    client.connect();
    for(int i = 0; i < numOfAI; i++)
    {
        m_Enemies.push_back(AI());
    }

    if (!font.loadFromFile("Adventure.otf"))
    {
        std::cerr << "No Font" << std::endl;
    }

}

World::~World()
{
    //dtor
}


void World::Run()
{
    unsigned short id = 1;
    //creates the render window
    sf::RenderWindow m_Window{sf::VideoMode(m_screenWidth, m_screenHeight), "T7087915 Roguelike"};

    //creates a view for the camera and mini map
    sf::View gameView(sf::FloatRect(200.f, 200.f, 500.f, 350.f));
    sf::View miniMap(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));
    miniMap.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));

    m_Map.Spawn();

    //Text Display setup
    hp.setFont(font);
    hpVal.setFont(font);
    score.setFont(font);
    scoreVal.setFont(font);
    damage.setFont(font);
    damageVal.setFont(font);
    hp.setCharacterSize(24);
    hpVal.setCharacterSize(24);
    score.setCharacterSize(24);
    scoreVal.setCharacterSize(24);

    while (m_Window.isOpen())
    {
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_Window.close();
        }

        if(m_Player.hp <= 0)
        {
        m_Window.close();
        }


        //Player and UI Updates
        m_Player.Update();
        m_Player.shoot(m_Window);
        UIUpdate();

        //Enemy Collision Loop through vector
        for(int i = 0; i < numOfAI; i++)
        {
            if(m_Enemies[i].IsAlive == true)
            {
                m_Enemies[i].Update(m_Player.m_pos);

                //Collision with Player damage
                if(m_Enemies[i].m_Enemy.getGlobalBounds().intersects(m_Player.m_Player.getGlobalBounds()))
                {

                    char type = m_Enemies[i].type;
                    switch(type)
                    {
                    case 'a':
                        m_Enemies[i].IsAlive = false;
                        m_Player.hp -= 10;
                        break;

                    case 'b':
                        m_Enemies[i].IsAlive = false;
                        m_Player.hp -= 8;
                        break;

                    case 'c':
                        m_Enemies[i].IsAlive = false;
                        m_Player.hp -= 6;
                        break;

                    case 'd':
                        m_Enemies[i].IsAlive = false;
                        m_Player.hp -= 4;
                        break;

                    case 'e':
                        m_Enemies[i].IsAlive = false;
                        m_Player.hp -= 2;
                        break;
                    }

                }

                //Collision with bullet
                for(int y= 0; y < m_Player.numBullets; y++)
                {
                    if(m_Enemies[i].m_Enemy.getGlobalBounds().intersects(m_Player.m_bullets[y].m_Projectile.getGlobalBounds()))
                    {
                        m_Enemies[i].IsAlive = false;
                        m_score += 10;
                    }

                }
            }

            //Spawn Enemy
            if(m_Enemies[i].IsAlive == false)
            {
                m_Enemies[i].Spawn(m_screenHeight, m_screenWidth);
            }
        }

        //client.send_tcp();
        //std::ostringstream oss;
        //oss << id << ":" << m_Player.m_pos.x << ":" << m_Player.m_pos.y;;
        //client.qsend.push(oss.str());

        //Window clear and render functions
        m_Window.clear();
        m_Player.Render(m_Window);
        m_Map.Render(m_Window);
        m_Window.draw(hp);
        m_Window.draw(hpVal);
        m_Window.draw(scoreVal);
        m_Window.draw(score);
        for(int i = 0; i < numOfAI; i++)
        {
            if(m_Enemies[i].IsAlive == true)
            {
                m_Enemies[i].Render(m_Window);
            }
        }



        //Move camera to player location and set to display the window
        gameView.setCenter(m_Player.m_pos);
        miniMap.setCenter(m_Player.m_pos);
        m_Window.setView(gameView);
        m_Window.display();







    }
}

void World::UIUpdate()
{
    //Ui Position set top left and update value numbers
    hp.setString("HP: " );
    hp.setPosition(m_Player.m_pos.x - 240, m_Player.m_pos.y - 170);
    hpVal.setString(std::to_string(m_Player.hp));
    hpVal.setPosition(m_Player.m_pos.x - 200, m_Player.m_pos.y - 170);
    score.setString("Score: " );
    score.setPosition(m_Player.m_pos.x - 240, m_Player.m_pos.y - 150);
    scoreVal.setString(std::to_string(m_score));
    scoreVal.setPosition(m_Player.m_pos.x - 180, m_Player.m_pos.y - 150);
}
