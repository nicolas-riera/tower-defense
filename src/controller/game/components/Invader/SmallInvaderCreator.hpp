#pragma once
#include "InvaderCreator.hpp"
#include "Invader.hpp"
#include "SmallInvader.hpp"

class SmallInvaderCreator : public InvaderCreator
{
    public:
        SmallInvaderCreator();
        ~SmallInvaderCreator();
        std::unique_ptr<Invader> createInvader(std::vector<Vector2> waypoints, short difficultyIndex) override;
};