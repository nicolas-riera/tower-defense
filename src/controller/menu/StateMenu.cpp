#include "StateMenu.hpp"
#include <cstdlib>

StateMenu::StateMenu(){};

StateMenu::~StateMenu(){};

void StateMenu::init(){
    this->view = std::make_unique<StateMenuView>();
    this->view->init();
    this->view->setContext(this->context);

    this->menuButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 350, 150, 50, "Play", [this]() {
        this->context->setState(DIFFICULTY);
    }, this->context));
    this->menuButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 410, 150, 50, "Options", [this]() {
        this->context->setState(OPTIONS);
    }, this->context));
    this->menuButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 470, 150, 50, "Scores", [this]() {
        this->context->setState(SCOREBOARD);
    }, this->context));
    this->menuButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 530, 150, 50, "Quit", []() {
        CloseWindow();
        exit(0);
    }, this->context));
};

void StateMenu::expose(){
    
    // Buttons
    for (auto& btn : this->menuButtons) {
        btn->Update();
    };
    
    this->view->display(this->menuButtons);
};