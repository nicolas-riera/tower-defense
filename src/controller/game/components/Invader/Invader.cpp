#include "Invader.hpp"

Invader::Invader(short x, short y, short life, short speed) : x(x), y(y), life(life), speed(speed){}

Invader::~Invader(){}

void Invader::update(Event event){
    if(event == SHOOT){
        --this->life;
    }
}