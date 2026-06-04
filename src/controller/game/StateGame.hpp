#pragma once
#include "../WindowState.hpp"
#include "../../view/game/StateGameView.hpp"
#include "components/Stage.hpp"

class StateGame : public WindowState
{
    private:
        std::unique_ptr<StateGameView> view;
        std::unique_ptr<Stage> stage;
        struct
        {
            int score = 0;
            int balance = 20;
            short wavecounter = 1;
        } gameStats;
    public:
        StateGame();
        ~StateGame();
        void init();
        void expose();
};