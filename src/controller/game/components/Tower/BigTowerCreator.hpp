#pragma once
#include "TowerCreator.hpp"
#include "Tower.hpp"
#include "BigTower.hpp"

class BigTowerCreator : public TowerCreator
{
    public:
        BigTowerCreator();
        ~BigTowerCreator();
        std::unique_ptr<Tower> createTower(short xMatrix, short yMatrix) override;
};