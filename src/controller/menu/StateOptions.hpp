#pragma once
#include "../WindowState.hpp"
#include "../../view/menu/StateOptionsView.hpp"
#include "../../model/PersistentDataModel.hpp"
#include "raylib.h"

class StateOptions : public WindowState
{
    private:
        PersistentDataModel dataModel;
        std::unique_ptr<StateOptionsView> view;
        ButtonsVector optionsButtons;
    public:
        StateOptions();
        ~StateOptions();
        void init();
        void expose(); 
};