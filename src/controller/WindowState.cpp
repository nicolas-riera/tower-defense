#include "WindowState.hpp"
#include "TowerDefense.hpp"

WindowState::WindowState(){};

WindowState::~WindowState(){};

void WindowState::setContext(TowerDefense* context) {
    this->context = context;
}

TowerDefense* WindowState::getContext() {
    return this->context;
}