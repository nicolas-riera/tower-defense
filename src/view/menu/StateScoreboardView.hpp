#pragma once
#include "../WindowView.hpp"
#include "../../controller/Button.hpp"
#include "../../model/PersistentDataModel.hpp"
#include "raylib.h"

class StateScoreboardView : public WindowView
{
    private:
        Texture2D background;
    public:
        StateScoreboardView();
        ~StateScoreboardView();
        void init();
        void display(const std::vector<std::unique_ptr<Button>>& buttons);
        void display(const std::vector<std::unique_ptr<Button>>& buttons, const std::vector<PersistentDataModel::PlayerScore>& scores, float scrollOffset);
};