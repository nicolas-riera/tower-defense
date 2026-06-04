#pragma once
#include "Invader.hpp"
#include <memory>

class InvaderCreator
{
    public:
        virtual std::unique_ptr<Invader> createInvader(short x, short y, short difficultyIndex) = 0;
};