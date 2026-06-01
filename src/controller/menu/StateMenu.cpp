#include "StateMenu.hpp"

StateMenu::StateMenu(){};

StateMenu::~StateMenu(){};

void StateMenu::init(){
    this->background = LoadTexture("assets/img/menu_background.png");
};

void StateMenu::expose(){
    Vector2 mousePos = GetMousePosition();

    DrawTextureEx(this->background, { 0.0f, 0.0f }, 0, 1, WHITE);
};