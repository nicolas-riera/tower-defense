#include "BigInvaderCreator.hpp"

BigInvaderCreator::BigInvaderCreator(){}

BigInvaderCreator::~BigInvaderCreator(){}

std::unique_ptr<Invader> BigInvaderCreator::createInvader(short x, short y, short difficultyIndex){
    return std::make_unique<BigInvader>(x, y, difficultyIndex);
}