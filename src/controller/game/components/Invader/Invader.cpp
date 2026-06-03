#include "Invader.hpp"

Invader::Invader(short life, short speed) : life(life), speed(speed){}

Invader::~Invader(){}

void Invader::update(Event event){
    if(event == SHOOT){
        --this->life;
    }
}