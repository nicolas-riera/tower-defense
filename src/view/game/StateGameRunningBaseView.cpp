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
    for (auto& tower : towers) {
        switch (tower->getType())
        {
        case SMALLTOWER:
            DrawTexture(textureSmallTower, tower->getXMatrix()*128, tower->getYMatrix()*128, WHITE);
            break;
        case BIGTOWER:
            DrawTexture(textureBigTower, tower->getXMatrix()*128, tower->getYMatrix()*128, WHITE);
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

