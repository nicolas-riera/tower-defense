#pragma once
#include "../WindowView.hpp"

class StateGameView: public WindowView
{
    public:
        StateGameView();
        ~StateGameView();
        void init();
        void display();
};