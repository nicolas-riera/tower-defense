#include "StateGameRunningView.hpp"

StateGameRunningView::StateGameRunningView(){};

StateGameRunningView::~StateGameRunningView(){
    UnloadTexture(textureSmallTower);
    UnloadTexture(textureBigTower);
    UnloadTexture(textureSmallInvader);
    UnloadTexture(textureBigInvader);
};

void StateGameRunningView::init() {
    textureSmallTower = LoadTexture("assets/img/towers/small_tower.png");
    textureBigTower = LoadTexture("assets/img/towers/small_tower.png"); 
    textureSmallInvader = LoadTexture("assets/img/invaders/small_invader_sprite.png");
    textureBigInvader = LoadTexture("assets/img/invaders/big_invader_sprite.png");
};

void StateGameRunningView::display(const ButtonsVector& buttons){};

void StateGameRunningView::display(const ButtonsVector& buttons, const std::vector<std::unique_ptr<Tower>>& towers, const std::vector<std::unique_ptr<Invader>>& invaders) {
    for (auto& btn : buttons) {
        btn->Draw();
    };
};

