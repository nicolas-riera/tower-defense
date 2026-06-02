#pragma once
#include "../../view/menu/StateScoreboardView.hpp"
#include "../WindowState.hpp"

class StateScoreboard : public WindowState
{
    private:
        std::unique_ptr<StateScoreboardView> view;
        std::vector<std::unique_ptr<Button>> scoreboardButtons;
        PersistentDataModel dataModel;
        std::vector<PersistentDataModel::PlayerScore> scores;
        float scrollOffset;
    public:
        StateScoreboard();
        ~StateScoreboard();
        void init();
        void expose();
};