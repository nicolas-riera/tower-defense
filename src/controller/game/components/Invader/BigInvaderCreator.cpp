#include "BigInvaderCreator.hpp"

BigInvaderCreator::BigInvaderCreator(){}

BigInvaderCreator::~BigInvaderCreator(){}

std::shared_ptr<Invader> BigInvaderCreator::createInvader(){
    return std::make_unique<BigInvader>();
}