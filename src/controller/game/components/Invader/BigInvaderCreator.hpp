#pragma once
#include "InvaderCreator.hpp"
#include "Invader.hpp"
#include "BigInvader.hpp"

class BigInvaderCreator : public InvaderCreator
{
    public:
        BigInvaderCreator();
        ~BigInvaderCreator();
        std::shared_ptr<Invader> createInvader();
};