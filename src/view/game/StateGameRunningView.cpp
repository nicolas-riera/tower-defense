#include "StateGameRunningView.hpp"

StateGameRunningView::StateGameRunningView(){};

StateGameRunningView::~StateGameRunningView() {
};

void StateGameRunningView::init() {

};

void StateGameRunningView::display(const ButtonsVector& buttons) {
    for (auto& btn : buttons) {
            btn->Draw();
        };
};

