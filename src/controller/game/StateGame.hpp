#pragma once
#include "../WindowState.hpp"
#include "../../view/game/StateGameView.hpp"
#include "components/Stage.hpp"
#include "components/GameStats.hpp"

class StateGame : public WindowState
{
    private:
        std::unique_ptr<StateGameView> view;
        std::unique_ptr<Stage> stage;
        std::vector<std::unique_ptr<Tower>> towers;
        std::vector<std::unique_ptr<Invader>> invaders;
        std::unique_ptr<GameStats> gameStats;
    public:
        StateGame();
        ~StateGame();
        void init();
        void expose();
};