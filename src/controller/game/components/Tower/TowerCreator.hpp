#pragma once
#include "Tower.hpp"
#include <memory>

class TowerCreator
{
    public:
        virtual std::unique_ptr<Tower> createTower(short xMatrix, short yMatrix) = 0;
};