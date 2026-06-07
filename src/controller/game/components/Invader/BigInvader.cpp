#include "BigInvader.hpp"

BigInvader::BigInvader(std::vector<Vector2> waypoints, short difficultyFactor) : Invader(waypoints, 10*difficultyFactor, 1*difficultyFactor, BIGINVADER){}

BigInvader::~BigInvader(){}