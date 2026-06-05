#include "BigTowerCreator.hpp"

BigTowerCreator::BigTowerCreator(){}

BigTowerCreator::~BigTowerCreator(){}

std::unique_ptr<Tower> BigTowerCreator::createTower(short xMatrix, short yMatrix){
    return std::make_unique<BigTower>(xMatrix, yMatrix);
}