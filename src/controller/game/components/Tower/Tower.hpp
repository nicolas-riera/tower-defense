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
    public:
        Tower(short xMatrix, short yMatrix, short attackDmg, short speed, short buyPrice, short sellPrice);
        ~Tower();
        short getXMatrix();
        short getYMatrix();
        void attack();
};