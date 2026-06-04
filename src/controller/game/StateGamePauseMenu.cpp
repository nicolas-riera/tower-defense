#include "StateGamePauseMenu.hpp"

StateGamePauseMenu::StateGamePauseMenu(){};

StateGamePauseMenu::~StateGamePauseMenu(){};

void StateGamePauseMenu::init(){
    this->view = std::make_unique<StateGamePauseMenuView>();
    this->view->init();
    this->view->setContext(this->context);
};

void StateGamePauseMenu::expose(){
    this->view->display();
};