#pragma once
#include "TowerCreator.hpp"
#include "Tower.hpp"
#include "SmallTower.hpp"

class SmallTowerCreator : public TowerCreator
{
    public:
        SmallTowerCreator();
        ~SmallTowerCreator();
        std::shared_ptr<Tower> createTower();
};