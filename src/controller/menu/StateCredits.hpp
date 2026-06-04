#pragma once
#include "../../view/menu/StateCreditsView.hpp"
#include "../WindowState.hpp"

class StateCredits : public WindowState
{
    private:
        std::unique_ptr<StateCreditsView> view;
        ButtonsVector creditsButtons;
    public:
        StateCredits();
        ~StateCredits();
        void init();
        void expose();
};