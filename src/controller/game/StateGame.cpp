#include "StateGame.hpp"

StateGame::StateGame(){};

StateGame::~StateGame(){};

void StateGame::init(){
    this->view = std::make_unique<StateGameView>();
    this->view->init();
    this->view->setContext(this->context);

    this->stage = std::make_unique<Stage>();
    this->stage->init(this->context->difficulty);

};

void StateGame::expose(){
    this->view->display(this->stage->grid, *this->gameStats, this->towers, this->invaders);
};