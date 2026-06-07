#pragma once
#include "../WindowState.hpp"
#include "GameWindowState.hpp"
#include "../../view/game/StateGameView.hpp"
#include "components/Stage.hpp"
#include "components/GameStats.hpp"
#include "../Enums.hpp"
#include "components/Tower/SmallTowerCreator.hpp"
#include "components/Tower/BigTowerCreator.hpp"
#include "components/Invader/SmallInvaderCreator.hpp"
#include "components/Invader/BigInvaderCreator.hpp"

class StateGame : public WindowState
{
    private:
        std::unique_ptr<StateGameView> view;
        std::unique_ptr<Stage> stage;
        std::vector<Vector2> masterwaypoints;
        std::unique_ptr<GameStats> gameStats;
        std::vector<std::unique_ptr<Tower>> towers;
        std::unique_ptr<SmallTowerCreator> smallTowerCreator;
        std::unique_ptr<BigTowerCreator> bigTowerCreator;
        std::vector<std::unique_ptr<Invader>> invaders;
        std::unique_ptr<SmallInvaderCreator> smallInvaderCreator;
        std::unique_ptr<BigInvaderCreator> bigInvaderCreator;
        std::unique_ptr<GameWindowState> state;
        GameStates nextState;
    public:
        TowerSelection selectedTower = EMPTY;
        StateGame();
        ~StateGame();
        void updateState();
        void setState(GameStates state);
        std::vector<std::unique_ptr<Tower>>& getTowers();
        void placeTower(short xMatrix, short yMatrix);
        std::vector<std::unique_ptr<Invader>>& getInvaders();
        const std::unique_ptr<SmallInvaderCreator>& getSmallInvaderCreator();
        const std::unique_ptr<BigInvaderCreator>& getBigInvaderCreator();
        GridMatrix& getGrid();
        const std::vector<Vector2>& getMasterwaypoints();
        int getBalance();
        const std::unique_ptr<StateGameView>& getView();
        void init();
        void expose();
};