#include "StateGameWon.hpp"

StateGameWon::StateGameWon(){};

StateGameWon::~StateGameWon(){};

void StateGameWon::init(){
    this->view = std::make_unique<StateGameWonView>();
    this->view->init();
    this->view->setContext(this->context);
};

void StateGameWon::expose(){
    this->view->display(this->gameWonButtons);
};