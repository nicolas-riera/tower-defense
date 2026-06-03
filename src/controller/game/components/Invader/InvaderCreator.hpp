#pragma once
#include "Invader.hpp"
#include <memory>

class InvaderCreator
{
    public:
        virtual std::shared_ptr<Invader> createInvader() = 0;
};