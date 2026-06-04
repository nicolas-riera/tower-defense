#pragma once
#include "InvaderCreator.hpp"
#include "Invader.hpp"
#include "BigInvader.hpp"

class BigInvaderCreator : public InvaderCreator
{
    public:
        BigInvaderCreator();
        ~BigInvaderCreator();
        std::unique_ptr<Invader> createInvader(short x, short y, short difficultyIndex) override;
};