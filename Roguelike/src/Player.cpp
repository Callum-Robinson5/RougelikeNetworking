#include "Player.h"

Player::Player()
{

    m_Player.setFillColor(sf::Color::Green);
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setPosition(sf::Vector2f(200,200));
    //ctor
}

Player::~Player()
{
    //dtor
}


void Player::Update()
{

    if(!m_Player.getGlobalBounds().intersects(m_shape.getGlobalBounds()))
    {

        m_pos = m_Player.getPosition();
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
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            m_Player.setPosition(m_pos);
        }

    }


void Player::Render(sf::RenderWindow& window)
{
    window.draw(m_Player);
    window.draw(m_shape);
}
