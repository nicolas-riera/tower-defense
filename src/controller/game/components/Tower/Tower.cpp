#include "Tower.hpp"
#include "../../../Enums.hpp"

Tower::Tower(short xMatrix, short yMatrix, short attackDmg, short speed, short buyPrice, short sellPrice) : xMatrix(xMatrix), yMatrix(yMatrix), attackDmg(attackDmg), speed(speed),  buyPrice(buyPrice), sellPrice(sellPrice){}
Tower::~Tower(){}
short Tower::getXMatrix(){
    return this->xMatrix;
}
short Tower::getYMatrix(){
    return this->yMatrix; 
}
void Tower::attack(){
    this->notifySubscribers(SHOOT);
}