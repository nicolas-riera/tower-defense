#pragma once
#include "../WindowView.hpp"
#include "../../controller/Button.hpp"
#include "raylib.h"

class StateOptionsView : public WindowView
{
    private:
        Texture2D background;
    public:
        StateOptionsView();
        ~StateOptionsView();
        void init();
        void display(const std::vector<std::unique_ptr<Button>>& buttons);
};