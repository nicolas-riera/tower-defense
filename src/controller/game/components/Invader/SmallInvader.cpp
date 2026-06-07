#include "SmallInvader.hpp"

SmallInvader::SmallInvader(std::vector<Vector2> waypoints, short difficultyFactor) : Invader(waypoints, 5*difficultyFactor, 1*difficultyFactor, SMALLINVADER){}

SmallInvader::~SmallInvader(){}