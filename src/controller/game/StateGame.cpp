#include "StateGame.hpp"

#include "StateGameRunning.hpp"
#include "StateGameRunningShop.hpp"
#include "StateGamePauseMenu.hpp"
#include "StateGameLost.hpp"
#include "StateGameWon.hpp"

StateGame::StateGame(){};

StateGame::~StateGame(){};

void StateGame::updateState()
{

    if (this->nextState == WAIT) return;

    switch (this->nextState)
    {
    case RUNNING:
        this->state = std::make_unique<StateGameRunning>();
        break;
    case RUNNINGSHOP:
        this->state = std::make_unique<StateGameRunningShop>();
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

void StateGame::setState(GameStates state)
{
    this->nextState = state;
}

std::vector<std::unique_ptr<Tower>>& StateGame::getTowers(){
    return this->towers;
}

void StateGame::placeTower(short xMatrix, short yMatrix) {
    std::unique_ptr<Tower> tower;

    if (this->selectedTower == SMALLTOWER) {
        tower = this->smallTowerCreator->createTower(xMatrix, yMatrix);
    } else {
        tower = this->bigTowerCreator->createTower(xMatrix, yMatrix);
    };

    this->towers.push_back(std::move(tower));

    this->gameStats->balance -= (selectedTower == SMALLTOWER) ? 20 : 60;
};

std::vector<std::unique_ptr<Invader>>& StateGame::getInvaders(){
    return this->invaders;
}

GridMatrix& StateGame::getGrid() {
    return this->stage->grid;
};

int StateGame::getBalance() {
    return this->gameStats->balance;
}

void StateGame::init(){

    this->view = std::make_unique<StateGameView>();
    this->view->init();
    this->view->setContext(this->context);

    this->stage = std::make_unique<Stage>();
    this->stage->init(this->context->difficulty);
    this->gameStats = std::make_unique<GameStats>();

    this->smallTowerCreator = std::make_unique<SmallTowerCreator>();
    this->bigTowerCreator = std::make_unique<BigTowerCreator>();
    this->smallInvaderCreator = std::make_unique<SmallInvaderCreator>();
    this->bigInvaderCreator = std::make_unique<BigInvaderCreator>();
    this->invaders.push_back(smallInvaderCreator->createInvader(40,40,1));
    this->towers.push_back(smallTowerCreator->createTower(0,0));

    this->setState(RUNNING);
};

void StateGame::expose(){

    this->updateState();
      
    // Main view
    this->view->display(this->stage->grid, *this->gameStats);

    // State logic/view
    this->state->expose();
};