#pragma once
#include "../WindowState.hpp"

class StateGameWon : public WindowState
{
    public:
        StateGameWon();
        ~StateGameWon();
        void init();
        void expose();
};