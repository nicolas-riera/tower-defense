#pragma once
#include "GameWindowState.hpp"
#include <memory>
#include "../../view/game/StateGameLostView.hpp"

class StateGameLost : public GameWindowState
{
    private:
        std::unique_ptr<StateGameLostView> view;
    public:
        StateGameLost();
        ~StateGameLost();
        void init();
        void expose();
};