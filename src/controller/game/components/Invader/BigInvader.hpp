#pragma once
#include "Invader.hpp"

class BigInvader : public Invader
{
    public:
        BigInvader(std::vector<Vector2> waypoints, short difficultyFactor);
        ~BigInvader();
};