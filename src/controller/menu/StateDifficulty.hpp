#pragma once
#include "../WindowState.hpp"

class StateDifficulty : public WindowState
{
    public:
        StateDifficulty();
        ~StateDifficulty();
        void init();
        void expose();
};