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

        void Run(int difficulty);

    protected:

    private:

    class Network_Client client;

    int m_screenWidth{1280};
    int m_screenHeight{720};
    Wall m_wall;
    Player m_Player;
    Map m_Map;
    int difficulty{3};

    class AI m_Enemy;
    int numOfAI{10};
    std::vector<AI> m_Enemies;

};

#endif // WORLD_H
