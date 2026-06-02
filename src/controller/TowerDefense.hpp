#pragma once
#include <memory>
#include "EnumStates.hpp"
#include "WindowState.hpp"

class TowerDefense
{
    private:
        std::unique_ptr<WindowState> state;
        enumStates nextState;
    public:
        const int screenWidth = 1280;
        const int screenHeight = 720;
        TowerDefense();
        ~TowerDefense();
        void updateState();
        void setState(enumStates state);
        void init();
        void show();
};
