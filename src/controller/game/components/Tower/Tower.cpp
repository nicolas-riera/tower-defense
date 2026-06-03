#include "Tower.hpp"
#include "../../../Enums.hpp"

Tower::Tower(short attackDmg, short speed, short buyPrice, short sellPrice) : attackDmg(attackDmg), speed(speed),  buyPrice(buyPrice), sellPrice(sellPrice){}
Tower::~Tower(){}
void Tower::attack(){
    this->notifySubscribers(SHOOT);
}