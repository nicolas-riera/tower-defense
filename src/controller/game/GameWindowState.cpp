#include "GameWindowState.hpp"
#include "StateGame.hpp"

GameWindowState::GameWindowState(){};

void GameWindowState::setContext(StateGame* context) {
    this->context = context;
}

StateGame* GameWindowState::getContext() {
    return this->context;
}