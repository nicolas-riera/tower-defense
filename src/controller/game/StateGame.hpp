#pragma once
#include "../WindowState.hpp"

class StateGame : public WindowState
{
    public:
        StateGame();
        ~StateGame();
        void init();
        void expose();
};