#pragma once
#include "../WindowState.hpp"

class StateGameLost : public WindowState
{
    public:
        StateGameLost();
        ~StateGameLost();
        void init();
        void expose();
};