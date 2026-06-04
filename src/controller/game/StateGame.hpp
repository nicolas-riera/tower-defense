#pragma once
#include "../WindowState.hpp"
#include "GameWindowState.hpp"
#include "../../view/game/StateGameView.hpp"
#include "components/Stage.hpp"
#include "components/GameStats.hpp"
#include "../Enums.hpp"

class StateGame : public WindowState
{
    private:
        std::unique_ptr<StateGameView> view;
        std::unique_ptr<Stage> stage;
        std::unique_ptr<GameStats> gameStats;
        std::unique_ptr<GameWindowState> state;
        GameStates nextState;
    public:
        StateGame();
        ~StateGame();
        void updateState();
        void setState(GameStates state);
        void init();
        void expose();
};