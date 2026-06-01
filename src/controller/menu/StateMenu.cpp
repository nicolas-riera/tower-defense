#include "StateMenu.hpp"

StateMenu::StateMenu(){};

StateMenu::~StateMenu(){};

void StateMenu::init(){
    this->view = std::make_unique<StateMenuView>();
    this->view->init();
    this->view->setContext(this->context);
};

void StateMenu::expose(){
    Vector2 mousePos = GetMousePosition();
    // float frameHeight = (float)button.height/NUM_FRAMES;
    
    this->view->display();
};