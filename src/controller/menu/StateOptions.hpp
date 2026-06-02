#pragma once
#include "../WindowState.hpp"

class StateOptions : public WindowState
{
    public:
        StateOptions();
        ~StateOptions();
        void init();
        void expose();
};