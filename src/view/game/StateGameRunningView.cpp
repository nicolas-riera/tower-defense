#include "StateGameRunningView.hpp"
#include <iostream>

StateGameRunningView::StateGameRunningView(){};

StateGameRunningView::~StateGameRunningView(){
    UnloadTexture(textureSmallTower);
    UnloadTexture(textureBigTower);
    UnloadTexture(textureSmallInvader);
    UnloadTexture(textureBigInvader);
};

void StateGameRunningView::init() {
    textureSmallTower = LoadTexture("assets/img/towers/small_tower.png");
    textureBigTower = LoadTexture("assets/img/towers/big_tower.png"); 
    textureSmallInvader = LoadTexture("assets/img/invaders/small_invader_sprite.png");
    textureBigInvader = LoadTexture("assets/img/invaders/big_invader_sprite.png");
    currentFrame = 0;
    framesSpeed = 8;
    frameRec = { 0.0f, 0.0f, (float)textureSmallInvader.width/6, (float)textureSmallInvader.height };
};

void StateGameRunningView::display(const ButtonsVector& buttons){};

void StateGameRunningView::display(const ButtonsVector& buttons, const std::vector<std::unique_ptr<Tower>>& towers, const std::vector<std::unique_ptr<Invader>>& invaders) {
    for (auto& btn : buttons) {
        btn->Draw();
    };
    float finalScale = this->context->getView()->getFinalScale();
    float scaledTileSize = 128.0f * finalScale;
    for (auto& tower : towers) {
        float posX = this->context->getView()->getOffsetX() + (static_cast<float>(tower->getXMatrix()) * scaledTileSize);
        float posY = this->context->getView()->getOffsetY() + (static_cast<float>(tower->getYMatrix()) * scaledTileSize);
        Vector2 position = { posX, posY };

        switch (tower->getType())
        {
        case SMALLTOWER:
            DrawTextureEx(textureSmallTower, position, 0.0f, finalScale, WHITE);
            break;
        case BIGTOWER:
            DrawTextureEx(textureBigTower, position, 0.0f, finalScale, WHITE);
            break;
        default:
            break;
        }
    };
    framesCounter++;

    if (framesCounter >= (60/framesSpeed))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 5) currentFrame = 0;

        frameRec.x = (float)currentFrame*(float)textureSmallInvader.width/6;
    }

    for (auto& invader : invaders) {
        float posX = this->context->getView()->getOffsetX() + (static_cast<float>(invader->x) * scaledTileSize);
        float posY = this->context->getView()->getOffsetY() + (static_cast<float>(invader->y) * scaledTileSize);
        Vector2 position = { posX, posY };

        switch (invader->getType())
        {
        case SMALLINVADER:
            DrawTextureRec(textureSmallInvader, frameRec, position, WHITE);
            break;
        case BIGINVADER:
            DrawTextureRec(textureBigInvader, frameRec, position, WHITE);
            break;
        default:
            break;
        }
    };
};

