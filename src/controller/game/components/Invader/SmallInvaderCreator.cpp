#include "SmallInvaderCreator.hpp"

SmallInvaderCreator::SmallInvaderCreator(){}

SmallInvaderCreator::~SmallInvaderCreator(){}

std::shared_ptr<Invader> SmallInvaderCreator::createInvader(){
    return std::make_unique<SmallInvader>();
}