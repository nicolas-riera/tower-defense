#pragma once
#include "../WindowView.hpp"
#include "../../controller/game/components/Stage.hpp"
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
        void display(const std::vector<std::unique_ptr<Button>>& buttons) override;
        void display(const GridMatrix& grid);
};