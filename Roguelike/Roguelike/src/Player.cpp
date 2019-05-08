#include "Player.h"



Player::Player(Wall &wall):
    m_wall(wall)
{

    m_Player.setFillColor(sf::Color::Green);
    m_Player.setPosition(100, -200);

    //adds 10 default bullets to prevent miss rendering when there is nothing there
    for(int i = 0; i < 10; i++)
    {
        m_bullets.push_back(Projectile());
    }

}

Player::~Player()
{
    //dtor

}



void Player::p_Move()
{
    wall_collision = false;
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

    //Collisions with walls bool, resets player position to previous before the move if it is colliding
    for (auto const& it : m_wall.wallsList())
    {
        wall_collision = (m_Player.getGlobalBounds().intersects(it.getGlobalBounds())) || wall_collision;
    }

    if(wall_collision == true)
    {
        m_Player.setPosition(m_pos);
    }
}

void Player::Update()
{
    //Update for player move and bullets
    std::thread(&Player::p_Move, this).join();
    for(int i = 0; i < numBullets; i++)
    {
        if(m_bullets[i].m_alive == true)
        {
            m_bullets[i].Update();
        }
    }
}

void Player::shoot(sf::RenderWindow& window)
{
    //Shoots bullets on left mouse using mouse coordinates in the window
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        m_bullets.push_back(Projectile());
        numBullets += 1;
        m_bullets[numBullets].shootProj(m_pos, mousePosition);
    }
}




void Player::Render(sf::RenderWindow& window)
{
    //Renders bullets and player
    for(int i = 0; i < numBullets; i++)
    {
        m_bullets[i].Render(window);
    }
    window.draw(m_Player);
}
