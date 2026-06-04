#pragma once
#include "GameWindowState.hpp"
#include <memory>
#include "../../view/game/StateGameRunningView.hpp"

class StateGameRunning : public GameWindowState
{
    private:
        std::unique_ptr<StateGameRunningView> view;

    public:
        StateGameRunning();
        ~StateGameRunning();
        void init();
        void expose();
};