#include "SmallTowerCreator.hpp"

SmallTowerCreator::SmallTowerCreator(){}

SmallTowerCreator::~SmallTowerCreator(){}

std::unique_ptr<Tower> SmallTowerCreator::createTower(){
    return std::make_unique<SmallTower>();
}