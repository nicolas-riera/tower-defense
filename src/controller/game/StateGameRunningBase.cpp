#include "StateGameRunningBase.hpp"

StateGameRunningBase::StateGameRunningBase(){};

StateGameRunningBase::~StateGameRunningBase(){};

void StateGameRunningBase::init(){
    this->view = std::make_unique<StateGameRunningBaseView>();
    this->view->init();
    this->view->setContext(this->context);

    this->gameRunningButtons.push_back(std::make_unique<Button>(695, 660, 220, 50, "Small Tower (20 G)", [this]() {
        this->context->setState(RUNNINGSHOP);
    }, this->context->getContext()));

    this->gameRunningButtons.push_back(std::make_unique<Button>(930, 660, 220, 50, "Big Tower (60 G)", [this]() {
            
    }, this->context->getContext()));

    this->gameRunningButtons.push_back(std::make_unique<Button>(1165, 660, 100, 50, "Pause", [this]() {
        this->context->setState(PAUSEMENU);
    }, this->context->getContext()));
};

void StateGameRunningBase::expose(){

    for (auto& btn : this->gameRunningButtons) {
        btn->Update();
    };

    this->view->display(this->gameRunningButtons, this->context->getTowers(), this->context->getInvaders());
};