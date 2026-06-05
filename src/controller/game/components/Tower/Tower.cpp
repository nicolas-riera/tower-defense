#include "Tower.hpp"
#include "../../../Enums.hpp"

Tower::Tower(short xMatrix, 
             short yMatrix, 
             short attackDmg, 
             short speed, 
             short buyPrice, 
             short sellPrice, 
             TowerSelection towerType) : 
                                        xMatrix(xMatrix), 
                                        yMatrix(yMatrix), 
                                        attackDmg(attackDmg), 
                                        speed(speed),  
                                        buyPrice(buyPrice), 
                                        sellPrice(sellPrice), 
                                        towerType(towerType){}
Tower::~Tower(){}
short Tower::getXMatrix(){
    return this->xMatrix;
}
short Tower::getYMatrix(){
    return this->yMatrix; 
}
TowerSelection Tower::getType(){
    return this->towerType;
}
void Tower::attack(){
    this->notifySubscribers(SHOOT);
}