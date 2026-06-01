#pragma once
#include "../WindowState.hpp"

class StateCredits : public WindowState
{
    public:
        StateCredits();
        ~StateCredits();
        void init();
        void expose();
};