#include "StateGamePauseMenu.hpp"

StateGamePauseMenu::StateGamePauseMenu(){};

StateGamePauseMenu::~StateGamePauseMenu(){};

void StateGamePauseMenu::init(){
    this->view = std::make_unique<StateGamePauseMenuView>();
    this->view->init();
    this->view->setContext(this->context);

    this->gamePauseMenuButtons.push_back(std::make_unique<Button>((this->context->getContext()->screenWidth / 2) - 75, 350, 150, 50, "Resume", [this]() {
        this->context->setState(RUNNING);
    }, this->context->getContext()));

    this->gamePauseMenuButtons.push_back(std::make_unique<Button>((this->context->getContext()->screenWidth / 2) - 75, 410, 150, 50, "Restart", [this]() {
        this->context->getContext()->setState(GAME); 
    }, this->context->getContext()));

    this->gamePauseMenuButtons.push_back(std::make_unique<Button>((this->context->getContext()->screenWidth / 2) - 75, 470, 150, 50, "Quit", [this]() {
        this->context->getContext()->setState(MENU);
    }, this->context->getContext()));
};

void StateGamePauseMenu::expose(){

    for (auto& btn : this->gamePauseMenuButtons) {
        btn->Update();
    };

    this->view->display(this->gamePauseMenuButtons);
};