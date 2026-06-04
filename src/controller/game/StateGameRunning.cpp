#include "StateGameRunning.hpp"

StateGameRunning::StateGameRunning(){};

StateGameRunning::~StateGameRunning(){};

void StateGameRunning::init(){
    this->view = std::make_unique<StateGameRunningView>();
    this->view->init();
    this->view->setContext(this->context);

    this->gameRunningButtons.push_back(std::make_unique<Button>(500, 350, 150, 50, "Small Tower (20 Gold)", [this]() {
        
    }, this->context->getContext()));
    this->gameRunningButtons.push_back(std::make_unique<Button>(600, 350, 150, 50, "Big Tower (60 Gold)", [this]() {
        
    }, this->context->getContext()));
    this->gameRunningButtons.push_back(std::make_unique<Button>(700, 350, 150, 50, "Pause", [this]() {
        this->context->setState(PAUSEMENU);
    }, this->context->getContext()));
};

void StateGameRunning::expose(){
    this->view->display(this->gameRunningButtons, this->context->getTowers(), this->context->getInvaders());
};