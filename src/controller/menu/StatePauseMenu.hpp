#pragma once
#include "../WindowState.hpp"

class StatePauseMenu : public WindowState
{
    public:
        StatePauseMenu();
        ~StatePauseMenu();
        void init();
        void expose();
};