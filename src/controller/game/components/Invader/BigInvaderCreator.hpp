#pragma once
#include "InvaderCreator.hpp"
#include "Invader.hpp"
#include "BigInvader.hpp"

class BigInvaderCreator : public InvaderCreator
{
    public:
        BigInvaderCreator();
        ~BigInvaderCreator();
        std::unique_ptr<Invader> createInvader(std::vector<Vector2> waypoints, short difficultyIndex) override;
};