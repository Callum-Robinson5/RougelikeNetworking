#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>


class Map
{
    public:
        Map();
        virtual ~Map();

        void Render(sf::RenderWindow& window);


    private:

    sf::RectangleShape m_test{sf::Vector2f(50,100)};
};

#endif // MAP_H
