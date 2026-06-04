#include "StateGameLostView.hpp"

StateGameLostView::StateGameLostView(){};

StateGameLostView::~StateGameLostView() {
};

void StateGameLostView::init() {

};

void StateGameLostView::display(const ButtonsVector& buttons) {
    for (auto& btn : buttons) {
        btn->Draw();
    };
};

