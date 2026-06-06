#include "SmallInvader.hpp"

SmallInvader::SmallInvader(short x, short y, short difficultyFactor) : Invader(x, y, 5*difficultyFactor, 2*difficultyFactor, SMALLINVADER){}

SmallInvader::~SmallInvader(){}