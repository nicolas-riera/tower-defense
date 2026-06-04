#pragma once
#include "GameWindowView.hpp"
#include "raylib.h"

class StateGameLostView: public GameWindowView
{
    public:
        StateGameLostView();
        ~StateGameLostView();
        void init();
        void display(const ButtonsVector& buttons);
};