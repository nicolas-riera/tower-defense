#pragma once
#include "Invader.hpp"

class SmallInvader : public Invader
{
    public:
        SmallInvader(short x, short y, short difficultyFactor);
        ~SmallInvader();
};