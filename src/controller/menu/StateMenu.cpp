#include "StateMenu.hpp"


StateMenu::StateMenu(){};

StateMenu::~StateMenu(){};

void StateMenu::init(){
    this->view = std::make_unique<StateMenuView>();
    this->view->init();
};

void StateMenu::expose(){
    Vector2 mousePos = GetMousePosition();
    this->view->display();
};