#pragma once
#include "../../../events/Publisher.hpp"

class Tower : public Publisher
{
    private:
        short attackDmg;
        short speed;
        short buyPrice;
        short sellPrice;
    public:
        Tower(short attackDmg, short speed, short buyPrice, short sellPrice);
        ~Tower();
        void attack();
};