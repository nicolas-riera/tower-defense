#include "StateGameRunning.hpp"

void StateGameRunning::init(){
    StateGameRunningBase::init();
    this->view = std::make_unique<StateGameRunningView>();
    this->view->init();
    this->view->setContext(this->context);        
};

void StateGameRunning::expose(){
    StateGameRunningBase::expose();
    this->view->display(this->context->getInvaders());
};