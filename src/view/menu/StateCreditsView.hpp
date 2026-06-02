#pragma once
#include "../WindowView.hpp"
#include "../../controller/Button.hpp"
#include "raylib.h"

class StateCreditsView : public WindowView
{
    private:
        Texture2D background;
        Texture2D arthur_pfp;
        Texture2D nicolas_pfp;
    public:
        StateCreditsView();
        ~StateCreditsView();
        void init();
        void display(const std::vector<std::unique_ptr<Button>>& buttons);
};