#pragma once
#include "GameWindowView.hpp"
#include "../../controller/game/components/Invader/Invader.hpp"
#include "../../controller/game/components/Tower/Tower.hpp"
#include "raylib.h"

class StateGameRunningView: public GameWindowView
{
    private:
        Texture2D textureSmallTower;
        Texture2D textureBigTower; 
        Texture2D textureSmallInvader;
        Texture2D textureBigInvader;
    public:
        StateGameRunningView();
        ~StateGameRunningView();
        void init();
        void display(const ButtonsVector& buttons);
        void display(const ButtonsVector& buttons, const std::vector<std::unique_ptr<Tower>>& towers, const std::vector<std::unique_ptr<Invader>>& invaders);
};