#include "StateDifficulty.hpp"

StateDifficulty::StateDifficulty(){};

StateDifficulty::~StateDifficulty(){};

void StateDifficulty::init(){
    this->view = std::make_unique<StateDifficultyView>();
    this->view->init();
    this->view->setContext(this->context);

    this->difficultyButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 350, 150, 50, "Easy", []() {
        // this->
    }, this->context));
    this->difficultyButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 410, 150, 50, "Normal", []() {
       
    }, this->context));
    this->difficultyButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 470, 150, 50, "Hard", [this]() {

    }, this->context));
    this->difficultyButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 550, 150, 50, "Back", [this]() {
        this->context->setState(MENU);
    }, this->context));
};

void StateDifficulty::expose(){
    // Buttons
    for (auto& btn : this->difficultyButtons) {
        btn->Update();
    };
    
    this->view->display(this->difficultyButtons);
};