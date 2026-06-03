#pragma once
#include "InvaderCreator.hpp"
#include "Invader.hpp"
#include "SmallInvader.hpp"

class SmallInvaderCreator : public InvaderCreator
{
    public:
        SmallInvaderCreator();
        ~SmallInvaderCreator();
        std::shared_ptr<Invader> createInvader();
};