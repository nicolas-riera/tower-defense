#include "StateGamePauseMenuView.hpp"

StateGamePauseMenuView::StateGamePauseMenuView(){};

StateGamePauseMenuView::~StateGamePauseMenuView() {
};

void StateGamePauseMenuView::init() {

};

void StateGamePauseMenuView::display(const ButtonsVector& buttons) {
    // Dark layer
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), { 0, 0, 0, 180 });

    DrawText("Pause", (this->context->getContext()->screenWidth / 2) - 50, 170, 32, WHITE);

    for (auto& btn : buttons) {
        btn->Draw();
    };
};

