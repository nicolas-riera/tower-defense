#include "StateMenuView.hpp"

StateMenuView::StateMenuView(){};

StateMenuView::~StateMenuView(){};

void StateMenuView::init(){
    this->background = LoadTexture("assets/img/menu_background.png");
};

void StateMenuView::display(){
    DrawTextureEx(this->background, { 0.0f, 0.0f }, 0, 1, WHITE);
};