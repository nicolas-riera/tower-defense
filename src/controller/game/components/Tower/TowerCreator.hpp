#pragma once
#include "Tower.hpp"
#include <memory>

class TowerCreator
{
    public:
        virtual std::shared_ptr<Tower> createTower() = 0;
};