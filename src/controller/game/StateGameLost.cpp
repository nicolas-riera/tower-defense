#include "StateGameLost.hpp"

StateGameLost::StateGameLost(){};

StateGameLost::~StateGameLost(){};

void StateGameLost::init(){
    this->view = std::make_unique<StateGameLostView>();
    this->view->init();
    this->view->setContext(this->context);
};

void StateGameLost::expose(){

    for (auto& btn : this->gameLostButtons) {
        btn->Update();
    };

    this->view->display(this->gameLostButtons);
};