#include "Player.h"

Player::Player()
{
    m_Player.setFillColor(sf::Color::Green);
    //ctor
}

Player::~Player()
{
    //dtor
}


void Player::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_Player.move(-5.0f, 0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_Player.move(5.0f, 0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_Player.move(0.0f, -5.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_Player.move(0.0f, 5.0f);
    }
}

void Player::Render(sf::RenderWindow& window)
{
    window.draw(m_Player);
}
