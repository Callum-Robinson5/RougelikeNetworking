#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <list>
#include <vector>

class Player
{
    public:
        Player();
        virtual ~Player();

        void Render(sf::RenderWindow& window);
        void Update();



    protected:

    private:



    //Stats
    float m_speed{5.0f};
    int hp{100};
    int mana{100};
    bool collision{false};
    sf::Vector2f m_pos{0.0f,0.0f};

    sf::RectangleShape m_Player{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape0{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape1{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape2{sf::Vector2f(25,25)};

    std::list<sf::RectangleShape> m_testShapes;





};

#endif // PLAYER_H
