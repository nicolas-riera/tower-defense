#include "StateCredits.hpp"

StateCredits::StateCredits(){};

StateCredits::~StateCredits(){};

void StateCredits::init(){
    this->view = std::make_unique<StateCreditsView>();
    this->view->init();
    this->view->setContext(this->context);

    this->creditsButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 550, 150, 50, "Back", [this]() {
        this->context->setState(OPTIONS);
    }));
};

void StateCredits::expose(){
    // Buttons
    for (auto& btn : this->creditsButtons) {
        btn->Update();
    };
    
    this->view->display(this->creditsButtons);
};