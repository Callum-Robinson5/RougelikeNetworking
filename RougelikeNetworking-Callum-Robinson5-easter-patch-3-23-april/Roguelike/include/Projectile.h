#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>



class Projectile
{
public:
    Projectile();
    virtual ~Projectile();

    void shootProj(sf::Vector2f spawnPos, sf::Vector2f mousePosition);
    void Update();
    void Render(sf::RenderWindow& window);
    sf::CircleShape m_Projectile{float(2.0f)};
    bool m_alive{false};

protected:

private:



    sf::Vector2f m_position;
    float angleShot2;
};

#endif // PROJECTILE_H
