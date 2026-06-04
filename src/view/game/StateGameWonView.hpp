#pragma once
#include "GameWindowView.hpp"
#include "raylib.h"

class StateGameWonView: public GameWindowView
{
    public:
        StateGameWonView();
        ~StateGameWonView();
        void init();
        void display();
};