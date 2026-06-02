#pragma once
#include "../WindowView.hpp"
#include "../../controller/Button.hpp"
#include "raylib.h"

class StateDifficultyView : public WindowView
{
    private:
        Texture2D background;
    public:
        StateDifficultyView();
        ~StateDifficultyView();
        void init();
        void display(const std::vector<std::unique_ptr<Button>>& buttons);
};