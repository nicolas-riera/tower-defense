#pragma once
#include "../WindowView.hpp"
#include "../../controller/game/components/Stage.hpp"

class StateGameView: public WindowView
{
    public:
        StateGameView();
        ~StateGameView();
        void init();
        void display(const std::vector<std::unique_ptr<Button>>& buttons) override;
        void display(const GridMatrix& grid);
};