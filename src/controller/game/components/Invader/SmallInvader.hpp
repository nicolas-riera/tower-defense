#pragma once
#include "Invader.hpp"

class SmallInvader : public Invader
{
    public:
        SmallInvader(short difficultyFactor);
        ~SmallInvader();
};