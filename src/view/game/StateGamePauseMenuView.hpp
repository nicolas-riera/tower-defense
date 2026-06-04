#pragma once
#include "GameWindowView.hpp"
#include "raylib.h"

class StateGamePauseMenuView: public GameWindowView
{
    public:
        StateGamePauseMenuView();
        ~StateGamePauseMenuView();
        void init();
        void display(const ButtonsVector& buttons);
};