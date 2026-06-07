#pragma once
#include "Invader.hpp"

class SmallInvader : public Invader
{
    public:
        SmallInvader(std::vector<Vector2> waypoints, short difficultyFactor);
        ~SmallInvader();
};