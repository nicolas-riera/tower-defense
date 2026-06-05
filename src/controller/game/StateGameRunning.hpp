#pragma once
#include "StateGameRunningBase.hpp"
#include "../../view/game/StateGameRunningView.hpp"

class StateGameRunning : public StateGameRunningBase {
    private:
        std::unique_ptr<StateGameRunningView> view;
    public:
        void init() override;
        void expose() override;
};