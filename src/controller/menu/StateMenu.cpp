#include "StateMenu.hpp"
#include "../Button.hpp"
#include "../EnumStates.hpp"
#include <cstdlib>

StateMenu::StateMenu(){};

StateMenu::~StateMenu(){};

void StateMenu::init(){
    this->view = std::make_unique<StateMenuView>();
    this->view->init();
    this->view->setContext(this->context);

    this->menuButtons.push_back(Button((this->context->screenWidth / 2) - 75, 350, 150, 50, "Play", [this]() {
        this->context->setState(GAME);
    }));
    this->menuButtons.push_back(Button((this->context->screenWidth / 2) - 75, 410, 150, 50, "Options", [this]() {
        this->context->setState(OPTIONS);
    }));
    this->menuButtons.push_back(Button((this->context->screenWidth / 2) - 75, 470, 150, 50, "Quit", []() {
        CloseWindow();
        exit(0);
    }));
};

void StateMenu::expose(){
    
    // Buttons
    for (auto& btn : this->menuButtons) {
        btn.Update();
    };
    
    this->view->display(this->menuButtons);
};