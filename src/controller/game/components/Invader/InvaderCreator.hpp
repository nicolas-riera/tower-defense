#pragma once
#include "Invader.hpp"
#include <memory>

class InvaderCreator
{
    public:
        virtual std::unique_ptr<Invader> createInvader(std::vector<Vector2> waypoints, short difficultyIndex) = 0;
};