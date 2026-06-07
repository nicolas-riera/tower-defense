#include "BigInvaderCreator.hpp"

BigInvaderCreator::BigInvaderCreator(){}

BigInvaderCreator::~BigInvaderCreator(){}

std::unique_ptr<Invader> BigInvaderCreator::createInvader(std::vector<Vector2> waypoints, short difficultyIndex){
    return std::make_unique<BigInvader>(waypoints, difficultyIndex);
}