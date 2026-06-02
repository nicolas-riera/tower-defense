#include "StateDifficultyView.hpp"

StateDifficultyView::StateDifficultyView(){};

StateDifficultyView::~StateDifficultyView(){
    UnloadTexture(this->background);
};

void StateDifficultyView::init(){
    this->background = LoadTexture("assets/img/menu_background.png");
};

void StateDifficultyView::display(const std::vector<std::unique_ptr<Button>>& buttons){
    DrawTextureEx(this->background, { 0.0f, 0.0f }, 0, 1, WHITE);

    DrawText("Choose a difficulty", (this->context->screenWidth / 2) - 150, 170, 32, BLACK);

    for (auto& btn : buttons) {
        btn->Draw();
    };
};