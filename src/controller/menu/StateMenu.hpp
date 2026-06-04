#pragma once
#include "../WindowState.hpp"
#include "../../view/menu/StateMenuView.hpp"
#include "raylib.h"

class StateMenu : public WindowState
{
    private:
        std::unique_ptr<StateMenuView> view;
        ButtonsVector menuButtons;
    public:
        StateMenu();
        ~StateMenu();
        void init();
        void expose(); 
};