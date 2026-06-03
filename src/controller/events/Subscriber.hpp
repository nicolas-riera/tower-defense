#pragma once
#include "../Enums.hpp"

class Subscriber{
    public:
        virtual void update(Event event) = 0;
};