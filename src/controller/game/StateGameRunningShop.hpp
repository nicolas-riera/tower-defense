#pragma once
#include "StateGameRunning.hpp"
#include "../../view/game/StateGameRunningShopView.hpp"
#include <memory>

class StateGameRunningShop : public StateGameRunning {
    private:
        std::unique_ptr<StateGameRunningShopView> view;
    public:
        void init() override;
        void expose() override;
};