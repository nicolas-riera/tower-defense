#pragma once
#include "Invader.hpp"

class BigInvader : public Invader
{
    public:
        BigInvader(short x, short y, short difficultyFactor);
        ~BigInvader();
};