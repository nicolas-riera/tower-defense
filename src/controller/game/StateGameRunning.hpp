#pragma once
#include "GameWindowState.hpp"
#include <memory>
#include <random>
#include "../../view/game/StateGameRunningView.hpp"

class StateGameRunning : public GameWindowState
{
    private:
        std::unique_ptr<StateGameRunningView> view;
        ButtonsVector gameRunningButtons;
        short framesCounter;
        short framesSpeed;
        std::mt19937 gen;
        std::uniform_int_distribution<int> distrib;
        int spawnTarget;
    public:
        StateGameRunning();
        ~StateGameRunning();
        void init();
        void expose();
};