#pragma once
#include "../WindowView.hpp"
#include "raylib.h"

class StateMenuView : public WindowView
{
    private:
        Texture2D background;
        Texture2D logo;
    public:
        StateMenuView();
        ~StateMenuView();
        void init();
        void display();
};