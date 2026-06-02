#include "StateOptionsView.hpp"

StateOptionsView::StateOptionsView(){};

StateOptionsView::~StateOptionsView(){};

void StateOptionsView::init(){
    this->background = LoadTexture("assets/img/menu_background.png");
};

void StateOptionsView::display(const std::vector<std::unique_ptr<Button>>& buttons){
    DrawTextureEx(this->background, { 0.0f, 0.0f }, 0, 1, WHITE);

    for (auto& btn : buttons) {
        btn->Draw();
    };
};