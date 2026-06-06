#pragma once
#include "GameWindowView.hpp"
#include "../../controller/game/components/Invader/Invader.hpp"
#include "../../controller/game/components/Tower/Tower.hpp"
#include "raylib.h"

class StateGameRunningBaseView: public GameWindowView
{
    private:
        Texture2D textureSmallTower;
        Texture2D textureBigTower;
        Texture2D textureSmallInvader;
        Texture2D textureBigInvader;
        short framesCounter;
        short framesSpeed;
        short currentFrame;
        Rectangle frameRec;
    public:
        StateGameRunningBaseView();
        ~StateGameRunningBaseView();
        void init();
        void display(const ButtonsVector& buttons);
        void display(const ButtonsVector& buttons, const std::vector<std::unique_ptr<Tower>>& towers, const std::vector<std::unique_ptr<Invader>>& invaders);
};