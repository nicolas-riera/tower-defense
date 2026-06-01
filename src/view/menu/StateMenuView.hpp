#pragma once
#include "../WindowView.hpp"
#include "../../controller/TowerDefense.hpp"
#include "raylib.h"

class StateMenuView : public WindowView
{
    protected:  
        TowerDefense* context;
    private:
        Texture2D background;
        Texture2D logo;
    public:
        StateMenuView();
        ~StateMenuView();
        void setContext(TowerDefense* context);
        void init();
        void display();
};