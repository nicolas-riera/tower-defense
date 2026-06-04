#pragma once
#include "GameWindowState.hpp"
#include <memory>
#include "../../view/game/StateGameRunningView.hpp"

class StateGameRunning : public GameWindowState
{
    private:
        std::unique_ptr<StateGameRunningView> view;
        std::vector<std::unique_ptr<Tower>> towers;
        std::vector<std::unique_ptr<Invader>> invaders;
    public:
        StateGameRunning();
        ~StateGameRunning();
        void init();
        void expose();
};