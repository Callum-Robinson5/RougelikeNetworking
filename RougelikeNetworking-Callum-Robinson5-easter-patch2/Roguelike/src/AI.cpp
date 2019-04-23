#include "AI.h"

AI::AI()
{
    //ctor
    m_Enemy.setFillColor(sf::Color::Red);
}

AI::~AI()
{
    //dtor
}

void AI::Spawn()
{

}

void AI::Update(sf::Vector2f pos)
{
    m_Playerpos = pos;
    m_Enemypos = m_Enemy.getPosition();
    float angle = atan2(m_Playerpos.y - m_Enemypos.y, m_Playerpos.x - m_Enemypos.x);
    // m_Enemy.move(cos(angle) * m_speed,0);
    //m_Enemy.move(0, sin(angle) * m_speed);
}
