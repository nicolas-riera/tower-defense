#pragma once
#include "../WindowView.hpp"

class StateGameView: public WindowView
{
    public:
        StateGameView();
        ~StateGameView();
        void init();
        void display(const std::vector<std::unique_ptr<Button>>& buttons) override;
        void display();
};