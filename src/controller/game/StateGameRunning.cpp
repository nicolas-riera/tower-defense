#include "StateGameRunning.hpp"

StateGameRunning::StateGameRunning(){};

StateGameRunning::~StateGameRunning(){};

void StateGameRunning::init(){
    this->view = std::make_unique<StateGameRunningView>();
    this->view->init();
    this->view->setContext(this->context);

    this->gameRunningButtons.push_back(std::make_unique<Button>(695, 660, 220, 50, "Small Tower (20 G)", [this]() {
        this->context->setState((this->context->selectedTower == EMPTY) ? RUNNINGSHOP : RUNNING);
        this->context->selectedTower = (this->context->selectedTower == EMPTY) ? SMALLTOWER : EMPTY;
    }, this->context->getContext()));

    this->gameRunningButtons.push_back(std::make_unique<Button>(930, 660, 220, 50, "Big Tower (60 G)", [this]() {
        this->context->setState((this->context->selectedTower == EMPTY) ? RUNNINGSHOP : RUNNING);
        this->context->selectedTower = (this->context->selectedTower == EMPTY) ? BIGTOWER : EMPTY;
    }, this->context->getContext()));

    this->gameRunningButtons.push_back(std::make_unique<Button>(1165, 660, 100, 50, "Pause", [this]() {
        this->context->setState(PAUSEMENU);
    }, this->context->getContext()));

    this->gameRunningButtons[0]->UpdateText((this->context->selectedTower != EMPTY) ? "Cancel" : "Small Tower (20 G)");
    this->gameRunningButtons[1]->UpdateText((this->context->selectedTower != EMPTY) ? "Cancel" : "Big Tower (60 G)");
};

void StateGameRunning::expose(){

    for (auto& btn : this->gameRunningButtons) {
        btn->Update();
    };

    if (this->gameRunningButtons.size() >= 2) {
        this->gameRunningButtons[0]->SetActive(this->context->getBalance() >= 20 || this->context->selectedTower != EMPTY);
        this->gameRunningButtons[1]->SetActive(this->context->getBalance() >= 60 || this->context->selectedTower != EMPTY);
    }

    this->view->display(this->gameRunningButtons, this->context->getTowers(), this->context->getInvaders());
};