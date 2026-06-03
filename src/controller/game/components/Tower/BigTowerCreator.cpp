#include "BigTowerCreator.hpp"

BigTowerCreator::BigTowerCreator(){}

BigTowerCreator::~BigTowerCreator(){}

std::shared_ptr<Tower> BigTowerCreator::createTower(){
    return std::make_unique<BigTower>();
}