#pragma once
#include "GameWindowState.hpp"
#include <memory>
#include "../../view/game/StateGameWonView.hpp"

class StateGameWon : public GameWindowState
{
    private:
        std::unique_ptr<StateGameWonView> view;
        ButtonsVector gameWonButtons;
    public:
        StateGameWon();
        ~StateGameWon();
        void init();
        void expose();
};