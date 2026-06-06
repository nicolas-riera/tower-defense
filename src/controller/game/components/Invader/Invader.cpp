#include "Invader.hpp"

Invader::Invader(short x, short y, short life, short speed, InvaderSelection invaderType) : x(x), y(y), life(life), speed(speed), invaderType(invaderType){}

Invader::~Invader(){}

InvaderSelection Invader::getType(){
    return this->invaderType;
}

void Invader::update(Event event){
    if(event == SHOOT){
        --this->life;
    }
}