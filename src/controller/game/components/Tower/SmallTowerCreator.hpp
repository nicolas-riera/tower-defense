#pragma once
#include "TowerCreator.hpp"
#include "Tower.hpp"
#include "SmallTower.hpp"

class SmallTowerCreator : public TowerCreator
{
    public:
        SmallTowerCreator();
        ~SmallTowerCreator();
        std::unique_ptr<Tower> createTower() override;
};