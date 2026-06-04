#pragma once
#include "../WindowView.hpp"
#include "../../controller/game/components/Stage.hpp"
#include "../../controller/game/components/GameStats.hpp"
#include "../../controller/game/components/Tower/Tower.hpp"
#include "../../controller/game/components/Invader/Invader.hpp"

#include "raylib.h"

class StateGameView: public WindowView
{
    private:
        Texture2D textureBackground;
        Texture2D textureBlank;
        Texture2D textureWall;
        Texture2D texturePath;
        Texture2D textureStart;
        Texture2D textureEnd;
    public:
        StateGameView();
        ~StateGameView();
        void init();
        void display(const std::vector<std::unique_ptr<Button>>& buttons);
        void display(const GridMatrix& grid, const GameStats& gameStats);
};