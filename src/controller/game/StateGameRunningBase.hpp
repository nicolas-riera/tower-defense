#pragma once
#include "GameWindowState.hpp"
#include <memory>
#include "../../view/game/StateGameRunningBaseView.hpp"

class StateGameRunningBase : public GameWindowState
{
    private:
        std::unique_ptr<StateGameRunningBaseView> view;
        ButtonsVector gameRunningButtons;
    public:
        StateGameRunningBase();
        ~StateGameRunningBase();
        void init();
        void expose();
};