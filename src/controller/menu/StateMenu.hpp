#pragma once
#include "../WindowState.hpp"

class StateMenu : public WindowState
{
    public:
        StateMenu();
        ~StateMenu();
        void init();
        void expose();
};