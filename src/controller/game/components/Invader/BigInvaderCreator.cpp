#include "BigInvaderCreator.hpp"

BigInvaderCreator::BigInvaderCreator(){}

BigInvaderCreator::~BigInvaderCreator(){}

std::shared_ptr<Invader> BigInvaderCreator::createInvader(short x, short y, short difficultyIndex){
    return std::make_unique<BigInvader>(x, y, difficultyIndex);
}