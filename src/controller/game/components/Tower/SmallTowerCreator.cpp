#include "SmallTowerCreator.hpp"

SmallTowerCreator::SmallTowerCreator(){}

SmallTowerCreator::~SmallTowerCreator(){}

std::unique_ptr<Tower> SmallTowerCreator::createTower(short xMatrix, short yMatrix){
    return std::make_unique<SmallTower>(xMatrix, yMatrix);
}