#pragma once
#include <memory>
#include "../WindowState.hpp"
#include "../../view/menu/StateOptionsView.hpp"
#include "raylib.h"

class StateOptions : public WindowState
{
    private:
        std::unique_ptr<StateOptionsView> view;
        std::vector<std::unique_ptr<Button>> optionsButtons;
    public:
        StateOptions();
        ~StateOptions();
        void init();
        void expose(); 
};