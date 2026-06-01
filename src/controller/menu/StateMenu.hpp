#pragma once
#include "../WindowState.hpp"
#include "raylib.h"

class StateMenu : public WindowState
{
    private:
       Texture2D background;
    public:
        StateMenu();
        ~StateMenu();
        void init();
        void expose(); 
};