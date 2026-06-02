#include "StateScoreboard.hpp"
#include <algorithm>

StateScoreboard::StateScoreboard(){};

StateScoreboard::~StateScoreboard(){};

void StateScoreboard::init(){
    this->view = std::make_unique<StateScoreboardView>();
    this->view->init();
    this->view->setContext(this->context);

    this->scores = this->dataModel.load();

    // Scoreboard sorting
    std::sort(this->scores.begin(), this->scores.end(), [](const PersistentDataModel::PlayerScore& a, const PersistentDataModel::PlayerScore& b) {
        if (a.score != b.score) {
            return a.score > b.score; 
        }
        return a.difficulty > b.difficulty;
    });

    this->scoreboardButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 550, 150, 50, "Back", [this]() {
        this->context->setState(MENU);
    }));
};

void StateScoreboard::expose(){

    float mouseWheel = GetMouseWheelMove();
    if (mouseWheel != 0.0f) {
        this->scrollOffset += mouseWheel * 25.0f;
        
        float rowHeight = 40.0f;
        float tableHeight = 320.0f;
        float totalContentHeight = this->scores.size() * rowHeight;
        float maxScroll = totalContentHeight - tableHeight;
        
        if (maxScroll < 0.0f) maxScroll = 0.0f;
        if (this->scrollOffset > 0.0f) this->scrollOffset = 0.0f;
        if (this->scrollOffset < -maxScroll) this->scrollOffset = -maxScroll;
    }

    // Buttons
    for (auto& btn : this->scoreboardButtons) {
        btn->Update();
    };
    
    this->view->display(this->scoreboardButtons, this->scores, this->scrollOffset);
};