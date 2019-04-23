#include "Projectile.h"

Projectile::Projectile()
{
    //ctor
    //m_Projectile.setPosition(-100,-100);
}

Projectile::~Projectile()
{
    //dtor
}

void Projectile::shootProj(sf::Vector2f spawnPos, sf::Vector2f mousePosition)
{
     m_position = sf::Vector2f(spawnPos.x, spawnPos.y);
     m_Projectile.setPosition(m_position);
     float angleShot = atan2(mousePosition.y - m_position.y, mousePosition.x - m_position.x );
     angleShot2 = angleShot;
     m_alive = true;
}

void Projectile::Update()
{
    m_Projectile.move(cos(angleShot2) * 10.0f, 0);
    m_Projectile.move(0, sin(angleShot2) * 10.0f);
}

void Projectile::Render(sf::RenderWindow& window)
{

    window.draw(m_Projectile);
}
