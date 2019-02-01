#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player();
        virtual ~Player();

        void Render(sf::RenderWindow& window);
        void Update();

    protected:

    private:
    float m_speed{5.0f};
    sf::CircleShape m_Player{10.f};

};

#endif // PLAYER_H
