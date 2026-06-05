#include "StateGameRunningBaseView.hpp"

StateGameRunningBaseView::StateGameRunningBaseView(){};

StateGameRunningBaseView::~StateGameRunningBaseView(){
    UnloadTexture(textureSmallTower);
    UnloadTexture(textureBigTower);
    UnloadTexture(textureSmallInvader);
    UnloadTexture(textureBigInvader);
};

void StateGameRunningBaseView::init() {
    textureSmallTower = LoadTexture("assets/img/towers/small_tower.png");
    textureBigTower = LoadTexture("assets/img/towers/big_tower.png"); 
    textureSmallInvader = LoadTexture("assets/img/invaders/small_invader_sprite.png");
    textureBigInvader = LoadTexture("assets/img/invaders/big_invader_sprite.png");
};

void StateGameRunningBaseView::display(const ButtonsVector& buttons){};

void StateGameRunningBaseView::display(const ButtonsVector& buttons, const std::vector<std::unique_ptr<Tower>>& towers, const std::vector<std::unique_ptr<Invader>>& invaders) {
    for (auto& btn : buttons) {
        btn->Draw();
    };
    float finalScale = this->context->getView()->getFinalScale();
    float scaledTileSize = 128.0f * finalScale;
    for (auto& tower : towers) {
        // Calculate the exact screen position using the grid's offset and scale
        float posX = this->context->getView()->getOffsetX() + (static_cast<float>(tower->getXMatrix()) * scaledTileSize);
        float posY = this->context->getView()->getOffsetY() + (static_cast<float>(tower->getYMatrix()) * scaledTileSize);
        Vector2 position = { posX, posY };

        switch (tower->getType())
        {
        case SMALLTOWER:
            // DrawTextureEx resizes the texture using the finalScale factor
            DrawTextureEx(textureSmallTower, position, 0.0f, finalScale, WHITE);
            break;
        case BIGTOWER:
            DrawTextureEx(textureBigTower, position, 0.0f, finalScale, WHITE);
            break;
        default:
            break;
        }
    };
/*     for (auto& invader : invaders) {
        std::cout << invader->x << "\n";
        std::cout << invader->y << std::endl;
    }; */
};

