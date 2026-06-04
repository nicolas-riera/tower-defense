#include "StateGameRunning.hpp"

StateGameRunning::StateGameRunning(){};

StateGameRunning::~StateGameRunning(){};

void StateGameRunning::init(){
    this->view = std::make_unique<StateGameRunningView>();
    this->view->init();
    this->view->setContext(this->context);
};

void StateGameRunning::expose(){
    this->view->display();
};