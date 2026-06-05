#pragma once
#include "StateGameRunningBaseView.hpp"

class StateGameRunningView : public StateGameRunningBaseView {
    private:
        short frameCounter;
    public:
        StateGameRunningView();
        ~StateGameRunningView();
        void display(const std::vector<std::unique_ptr<Invader>>& invaders);
};