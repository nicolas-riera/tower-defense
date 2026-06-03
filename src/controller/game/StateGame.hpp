#pragma once
#include "../WindowState.hpp"
#include "../../view/game/StateGameView.hpp"
#include "components/Stage.hpp"

class StateGame : public WindowState
{
    private:
        std::unique_ptr<StateGameView> view;
        std::unique_ptr<Stage> stage;
    public:
        StateGame();
        ~StateGame();
        void init();
        void expose();
};