#pragma once
#include "GameWindowState.hpp"
#include <memory>
#include "../../view/game/StateGamePauseMenuView.hpp"

class StateGamePauseMenu : public GameWindowState
{
    private:
        std::unique_ptr<StateGamePauseMenuView> view;
        ButtonsVector gamePauseMenuButtons;
    public:
        StateGamePauseMenu();
        ~StateGamePauseMenu();
        void init();
        void expose();
};