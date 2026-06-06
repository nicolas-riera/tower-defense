#pragma once
#include "StateGameRunningView.hpp"
#include "raylib.h"

class StateGameRunningShopView: public GameWindowView
{
    public:
        StateGameRunningShopView();
        ~StateGameRunningShopView();
        void init();
        void display(const ButtonsVector& buttons);
        void display(const GridMatrix& grid, float windowWidth, float windowHeight);
};