#include "StateGameWonView.hpp"

StateGameWonView::StateGameWonView(){};

StateGameWonView::~StateGameWonView() {
};

void StateGameWonView::init() {

};

void StateGameWonView::display(const ButtonsVector& buttons) {
    for (auto& btn : buttons) {
        btn->Draw();
    };
};

