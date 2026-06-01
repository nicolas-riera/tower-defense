#include "StateMenuView.hpp"

StateMenuView::StateMenuView(){};

StateMenuView::~StateMenuView(){};

void StateMenuView::init(){
    this->background = LoadTexture("assets/img/menu_background.png");
    this->logo = LoadTexture("assets/img/logo.png");
};

void StateMenuView::display(){
    DrawTextureEx(this->background, { 0.0f, 0.0f }, 0, 1, WHITE);
    DrawTextureEx(this->logo, { (this->context->screenWidth - (this->logo.width * 0.4f)) / 2.0f, (this->context->screenHeight - (this->logo.height * 0.4f)) / 7.5f }, 0, 0.4f, WHITE);
};