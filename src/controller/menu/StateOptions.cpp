#include "StateOptions.hpp"

StateOptions::StateOptions(){};

StateOptions::~StateOptions(){};

void StateOptions::init(){
    this->view = std::make_unique<StateOptionsView>();
    this->view->init();
    this->view->setContext(this->context);

    this->optionsButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 350, 150, 50, "Music : ?", [this]() {
        this->optionsButtons[0]->UpdateText("Music : ");
    }));
    this->optionsButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 410, 150, 50, "SFX : ?", [this]() {
       this->optionsButtons[1]->UpdateText("SFX : ");
    }));
    this->optionsButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 470, 150, 50, "Credits", [this]() {
        this->context->setState(CREDITS);
    }));
    this->optionsButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 550, 150, 50, "Back", [this]() {
        this->context->setState(MENU);
    }));

    // Check if music and sfx are on or off
};

void StateOptions::expose(){
    // Buttons
    for (auto& btn : this->optionsButtons) {
        btn->Update();
    };
    
    this->view->display(this->optionsButtons);
};