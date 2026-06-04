#pragma once
#include "Tower.hpp"
#include <memory>

class TowerCreator
{
    public:
        virtual std::unique_ptr<Tower> createTower() = 0;
};