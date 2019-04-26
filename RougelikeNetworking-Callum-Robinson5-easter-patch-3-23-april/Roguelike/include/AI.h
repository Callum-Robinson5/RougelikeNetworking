#ifndef AI_H
#define AI_H
#include <SFML/Graphics.hpp>
#include "Projectile.h"


class AI
{
    public:
        AI();
       // AI();
        virtual ~AI();


        void Update(sf::Vector2f pos, int difficulty);
        void Spawn(int screenHeight, int ScreenWidth);
        void Render(sf::RenderWindow& window);
        bool IsAlive{false};
        sf::RectangleShape m_Enemy{sf::Vector2f(15,15)};
        int numBullets{0};
        class Projectile projectile;
    protected:

    private:



    float m_speed{2};
    float m_size{10};


    sf::Vector2f m_Playerpos{0,0};
    sf::Vector2f m_Enemypos{0,0};
};

#endif // AI_H
