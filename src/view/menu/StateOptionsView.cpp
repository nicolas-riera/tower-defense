#include "StateOptionsView.hpp"

StateOptionsView::StateOptionsView(){};

StateOptionsView::~StateOptionsView(){
    UnloadTexture(this->background);
};

void StateOptionsView::init(){
    this->background = LoadTexture("assets/img/menu_background.png");
};

void StateOptionsView::display(const std::vector<std::unique_ptr<Button>>& buttons){
    DrawTextureEx(this->background, { 0.0f, 0.0f }, 0, 1, WHITE);

    DrawText("OPTIONS", (this->context->screenWidth / 2) - 72, 170, 32, BLACK);

    for (auto& btn : buttons) {
        btn->Draw();
    };
};