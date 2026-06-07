#include "StateGameRunning.hpp"

StateGameRunning::StateGameRunning(){};

StateGameRunning::~StateGameRunning(){};

void StateGameRunning::init(){
    this->view = std::make_unique<StateGameRunningView>();
    this->view->init();
    this->view->setContext(this->context);

    this->framesCounter = 0;
    this->framesSpeed = 2;

    std::random_device rd;
    this->gen = std::mt19937(rd());
    this->distrib = std::uniform_int_distribution<int>(300, 1000);

    this->spawnTarget = this->distrib(this->gen) / this->framesSpeed;

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

    ++framesCounter;
    if (framesCounter >= this->spawnTarget)
    {   
        framesCounter = 0;
        
        int actualRolledValue = this->spawnTarget * this->framesSpeed;
        std::cout << actualRolledValue << std::endl; 
        
        if (actualRolledValue < 900){
            context->getInvaders().push_back(context->getSmallInvaderCreator()->createInvader(context->getMasterwaypoints(),1));
        } else {
            context->getInvaders().push_back(context->getBigInvaderCreator()->createInvader(context->getMasterwaypoints(),1));
        }
        
        this->spawnTarget = this->distrib(this->gen) / this->framesSpeed;
    }

    for (auto& btn : this->gameRunningButtons) {
        btn->Update();
    };

    if (this->gameRunningButtons.size() >= 2) {
        this->gameRunningButtons[0]->SetActive(this->context->getBalance() >= 20 || this->context->selectedTower != EMPTY);
        this->gameRunningButtons[1]->SetActive(this->context->getBalance() >= 60 || this->context->selectedTower != EMPTY);
    }
    for (auto& invader: this->context->getInvaders()){
        invader->move(GetFrameTime());
    }

    this->view->display(this->gameRunningButtons, this->context->getTowers(), this->context->getInvaders());
};