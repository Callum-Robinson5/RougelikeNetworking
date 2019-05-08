#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <list>
#include <vector>
#include "Wall.h"
#include "Map.h"
#include <thread>
#include "Projectile.h"

class Player
{
public:
    Player(Wall &wall);
    virtual ~Player();

    void Render(sf::RenderWindow& window);
    void Update();
    sf::Vector2f m_pos{0.0f,0.0f};
    void shoot(sf::RenderWindow& window);
    std::vector<Projectile> m_bullets;
    int numBullets{0};
    int hp{100};
    int ammo{100};
    sf::RectangleShape m_Player{sf::Vector2f(25,25)};


protected:

private:

    float m_speed{5.0f};
    bool wall_collision{false};
    Wall &m_wall;
    class Projectile projectile;
    void p_Move();
};

#endif // PLAYER_H