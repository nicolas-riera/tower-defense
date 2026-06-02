#pragma once
#include "../../view/menu/StateDifficultyView.hpp"
#include "../WindowState.hpp"

class StateDifficulty : public WindowState
{
    private:
        std::unique_ptr<StateDifficultyView> view;
        std::vector<std::unique_ptr<Button>> difficultyButtons;
    public:
        StateDifficulty();
        ~StateDifficulty();
        void init();
        void expose();
};