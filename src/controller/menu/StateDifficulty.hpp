#pragma once
#include "../../view/menu/StateDifficultyView.hpp"
#include "../WindowState.hpp"

class StateDifficulty : public WindowState
{
    private:
        std::unique_ptr<StateDifficultyView> view;
        std::vector<std::unique_ptr<Button>> difficultyButtons;
        void startGame(Difficulty difficulty);
    public:
        StateDifficulty();
        ~StateDifficulty();
        void init();
        void expose();
};