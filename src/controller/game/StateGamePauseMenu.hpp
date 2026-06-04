#pragma once
#include "GameWindowState.hpp"
#include <memory>
#include "../../view/game/StateGamePauseMenuView.hpp"

class StateGamePauseMenu : public GameWindowState
{
    private:
        std::unique_ptr<StateGamePauseMenuView> view;
    public:
        StateGamePauseMenu();
        ~StateGamePauseMenu();
        void init();
        void expose();
};