#ifndef WORLD_H
#define WORLD_H

#include "Map.h"
#include "Wall.h"
#include "Network_Client.h"
#include "AI.h"


class World
{
public:
    World();
    virtual ~World();

    void Run();

protected:

private:

    class Network_Client client;
    void UIUpdate();

    sf::Font font;
    int m_screenWidth{1280};
    int m_screenHeight{720};
    Wall m_wall;
    Player m_Player;
    Map m_Map;

    class AI m_Enemy;
    int numOfAI{40};
    int m_score{0};
    std::vector<AI> m_Enemies;
    sf::Text hp;
    sf::Text hpVal;
    sf::Text score;
    sf::Text scoreVal;
    sf::Text damage;
    sf::Text damageVal;

};

#endif // WORLD_H
