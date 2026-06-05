#pragma once
#include "../../../events/Publisher.hpp"

class Tower : public Publisher
{
    private:
        short attackDmg;
        short speed;
        short buyPrice;
        short sellPrice;
        short xMatrix;
        short yMatrix;
        TowerSelection towerType;
        
    public:
        Tower(short xMatrix, short yMatrix, short attackDmg, short speed, short buyPrice, short sellPrice, TowerSelection towerType);
        ~Tower();
        short getXMatrix();
        short getYMatrix();
        TowerSelection getType();
        void attack();
};