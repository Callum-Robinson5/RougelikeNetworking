#include "AI.h"
#include "iostream"

AI::AI()
{
    //ctor
    m_Enemy.setFillColor(sf::Color::White);
    m_Enemy.setPosition(500,500);
}

AI::~AI()
{
    //dtor
}

void AI::Spawn(int screenHeight, int ScreenWidth)
{
    int colour = rand()%5;
    int x = rand()%ScreenWidth;
    int y = rand()%screenHeight;
    m_Enemy.setPosition(x,y);
    if((rand()%200) == 0)
    {
        if(colour == 0)
        {
        m_Enemy.setFillColor(sf::Color::Cyan);
        m_speed = 1;
        }
        if(colour == 1)
        {
        m_Enemy.setFillColor(sf::Color::Blue);
        m_speed = 2;
        }
        if(colour == 2)
        {
        m_Enemy.setFillColor(sf::Color::Yellow);
        m_speed = 3;
        }
        if(colour == 3)
        {
        m_Enemy.setFillColor(sf::Color::Magenta);
        m_speed = 4;
        }
        if(colour == 4)
        {
        m_Enemy.setFillColor(sf::Color::Red);
        m_speed = 5;
        }
        IsAlive = true;
    }
}

void AI::Update(sf::Vector2f pos)
{
    m_Playerpos = pos;
    m_Enemypos = m_Enemy.getPosition();
    float angle = atan2(m_Playerpos.y - m_Enemypos.y, m_Playerpos.x - m_Enemypos.x);
    m_Enemy.move(cos(angle) * m_speed,0);
    m_Enemy.move(0, sin(angle) * m_speed);
}

void AI::Render(sf::RenderWindow& window)
{
    window.draw(m_Enemy);
}
