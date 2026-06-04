#pragma once
#include "GameWindowView.hpp"
#include "raylib.h"

class StateGameRunningView: public GameWindowView
{
    public:
        StateGameRunningView();
        ~StateGameRunningView();
        void init();
        void display(const ButtonsVector& buttons);
};