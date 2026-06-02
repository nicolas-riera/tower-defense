#include "StateMenu.hpp"
#include "../Button.hpp"
#include <iostream>

StateMenu::StateMenu(){};

StateMenu::~StateMenu(){};

void StateMenu::init(){
    this->view = std::make_unique<StateMenuView>();
    this->view->init();
    this->view->setContext(this->context);

    this->menuButtons.push_back(Button((this->context->screenWidth / 2) - 75, 350, 150, 50, "Play", []() {
        std::cout << "Play" << std::endl;
    }));
    this->menuButtons.push_back(Button((this->context->screenWidth / 2) - 75, 410, 150, 50, "Options", []() {
        std::cout << "Options" << std::endl;
    }));
    this->menuButtons.push_back(Button((this->context->screenWidth / 2) - 75, 470, 150, 50, "Quit", []() {
        std::cout << "Exit" << std::endl;
    }));
};

void StateMenu::expose(){
    
    // Buttons
    for (auto& btn : this->menuButtons) {
        btn.Update();
    };
    
    this->view->display(this->menuButtons);
};