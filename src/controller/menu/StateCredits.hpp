#pragma once
#include "../../view/menu/StateCreditsView.hpp"
#include "../WindowState.hpp"

class StateCredits : public WindowState
{
    private:
        std::unique_ptr<StateCreditsView> view;
        std::vector<std::unique_ptr<Button>> creditsButtons;
    public:
        StateCredits();
        ~StateCredits();
        void init();
        void expose();
};