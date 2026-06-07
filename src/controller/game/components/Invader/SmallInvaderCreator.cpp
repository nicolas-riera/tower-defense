#include "SmallInvaderCreator.hpp"

SmallInvaderCreator::SmallInvaderCreator(){}

SmallInvaderCreator::~SmallInvaderCreator(){}

std::unique_ptr<Invader> SmallInvaderCreator::createInvader(std::vector<Vector2> waypoints, short difficultyIndex){
    return std::make_unique<SmallInvader>(waypoints, difficultyIndex);
}