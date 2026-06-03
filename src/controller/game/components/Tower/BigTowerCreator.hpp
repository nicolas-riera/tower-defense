#pragma once
#include "TowerCreator.hpp"
#include "Tower.hpp"
#include "BigTower.hpp"

class BigTowerCreator : public TowerCreator
{
    public:
        BigTowerCreator();
        ~BigTowerCreator();
        std::shared_ptr<Tower> createTower();
};