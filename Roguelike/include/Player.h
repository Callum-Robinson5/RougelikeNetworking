#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

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
    sf::Vector2f m_pos{0.0f,0.0f};

    sf::RectangleShape m_Player{sf::Vector2f(25,25)};
    sf::RectangleShape m_shape{sf::Vector2f(25,25)};




};

#endif // PLAYER_H
