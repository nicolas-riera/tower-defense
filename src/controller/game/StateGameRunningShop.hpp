#pragma once
#include "StateGameRunningBase.hpp"
#include "../../view/game/StateGameRunningShopView.hpp"

class StateGameRunningShop : public StateGameRunningBase {
    public:
        void init() override;
        void expose() override;
};