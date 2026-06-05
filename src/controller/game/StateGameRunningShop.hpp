#pragma once
#include "StateGameRunningBase.hpp"
#include "../../view/game/StateGameRunningShopView.hpp"
#include <memory>

class StateGameRunningShop : public StateGameRunningBase {
    private:
        std::unique_ptr<StateGameRunningShopView> view;
    public:
        void init() override;
        void expose() override;
};