#include "SmallInvaderCreator.hpp"

SmallInvaderCreator::SmallInvaderCreator(){}

SmallInvaderCreator::~SmallInvaderCreator(){}

std::shared_ptr<Invader> SmallInvaderCreator::createInvader(short x, short y, short difficultyIndex){
    return std::make_unique<SmallInvader>(x, y, difficultyIndex);
}