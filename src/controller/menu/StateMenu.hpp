#pragma once
#include <memory>
#include "../WindowState.hpp"
#include "../../view/menu/StateMenuView.hpp"
#include "raylib.h"

class StateMenu : public WindowState
{
    private:
        std::unique_ptr<StateMenuView> view;
        std::vector<Button> menuButtons;
    public:
        StateMenu();
        ~StateMenu();
        void init();
        void expose(); 
};