#include "Player.h"

Player::Player()
{

    m_Player.setFillColor(sf::Color::Green);
    m_shape0.setFillColor(sf::Color::Red);
    m_shape0.setPosition(sf::Vector2f(200,200));
    m_shape1.setFillColor(sf::Color::Blue);
    m_shape1.setPosition(sf::Vector2f(150,200));
    m_shape2.setFillColor(sf::Color::Yellow);
    m_shape2.setPosition(sf::Vector2f(100,200));



    m_testShapes.push_front(m_shape1);
    m_testShapes.push_front(m_shape0);
    m_testShapes.push_front(m_shape2);





    //ctor
}

Player::~Player()
{
    //dtor
}


void Player::Update()
{

    collision = false;
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

    for(std::list<sf::RectangleShape>::iterator it = m_testShapes.begin(); it != m_testShapes.end(); ++it)
    {
        collision = (m_Player.getGlobalBounds().intersects(it->getGlobalBounds())) || collision;
    }

    if(collision == true)
    {
        m_Player.setPosition(m_pos);
    }
}


void Player::Render(sf::RenderWindow& window)
{
    window.draw(m_Player);
    for(std::list<sf::RectangleShape>::iterator it = m_testShapes.begin(); it != m_testShapes.end(); ++it)
    {
        window.draw(*it);
    }
}
