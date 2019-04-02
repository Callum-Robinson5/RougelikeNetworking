#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <list>
#include <vector>
#include "Wall.h"
#include <thread>


class Player
{
public:
    Player(Wall &wall);
    virtual ~Player();

    void Render(sf::RenderWindow& window);
    void Update();




protected:

private:

    //Stats
    float m_speed{5.0f};
    int hp{100};
    int mana{100};

    //Movement
    bool wall_collision{false};
    sf::Vector2f m_pos{0.0f,0.0f};

    Wall &m_wall;

    sf::RectangleShape m_Player{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape0{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape1{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape2{sf::Vector2f(25,25)};

    //Collisions


    //Thread
    std::vector<std::thread> testThreads;

    //Functions
    void p_Move();



};

#endif // PLAYER_H