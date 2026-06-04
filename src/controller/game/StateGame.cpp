#include "StateGame.hpp"

#include "StateGameRunning.hpp"
#include "StateGamePauseMenu.hpp"
#include "StateGameLost.hpp"
#include "StateGameWon.hpp"

StateGame::StateGame(){};

StateGame::~StateGame(){};

void StateGame::setState(GameStates state)
{
    this->nextState = state;
}

void StateGame::updateState()
{

    if (this->nextState == WAIT) return;

    switch (this->nextState)
    {
    case RUNNING:
        this->state = std::make_unique<StateGameRunning>();
        break;
    case PAUSEMENU:
        this->state = std::make_unique<StateGamePauseMenu>();
        break;
    case GAMELOST:
        this->state = std::make_unique<StateGameLost>();
        break;
    case GAMEWON:
        this->state = std::make_unique<StateGameWon>();
        break;
    default:
        break;
    }
    this->state->setContext(this);
    this->state->init();

    this->nextState = WAIT;
}

void StateGame::init(){

    this->stage = std::make_unique<Stage>();
    this->stage->init(this->context->difficulty);

    this->gameStats = std::make_unique<GameStats>();

    this->setState(RUNNING);
};

void StateGame::expose(){

    this->updateState();

    this->state->expose();
    // this->view->display(this->stage->grid, *this->gameStats);
};