#include "StateOptions.hpp"

StateOptions::StateOptions(){};

StateOptions::~StateOptions(){};

void StateOptions::init(){
    this->view = std::make_unique<StateOptionsView>();
    this->view->init();
    this->view->setContext(this->context);

    auto& soundMgr = this->context->getSoundManager();

    this->optionsButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 350, 150, 50, soundMgr.getIsMusicOn() ? "Music : On" : "Music : Off", [this]() {
        this->context->getSoundManager().setIsMusicOn(!this->context->getSoundManager().getIsMusicOn());
        this->optionsButtons[0]->UpdateText(this->context->getSoundManager().getIsMusicOn() ? "Music : On" : "Music : Off");
    }, this->context));
    this->optionsButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 410, 150, 50, soundMgr.getIsSfxOn() ? "SFX : On" : "SFX : Off", [this]() {
        this->context->getSoundManager().setIsSfxOn(!this->context->getSoundManager().getIsSfxOn());
        this->optionsButtons[1]->UpdateText(this->context->getSoundManager().getIsSfxOn() ? "SFX : On" : "SFX : Off");
    }, this->context));
    this->optionsButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 470, 150, 50, "Credits", [this]() {
        this->context->setState(CREDITS);
    }, this->context));
    this->optionsButtons.push_back(std::make_unique<Button>((this->context->screenWidth / 2) - 75, 550, 150, 50, "Back", [this]() {
        
        // Save when backing out
        PersistentDataModel::Config config;
        config.music = this->context->getSoundManager().getIsMusicOn();
        config.sfx = this->context->getSoundManager().getIsSfxOn();
        dataModel.saveConfig(config);

        this->context->setState(MENU);
    }, this->context));

    // Check if music and sfx are on or off
    if (this->context->getSoundManager().getIsMusicOn()) {
        this->optionsButtons[0]->UpdateText("Music : On");
    } else {
        this->optionsButtons[0]->UpdateText("Music : Off");
    }
    if (this->context->getSoundManager().getIsSfxOn()) {
        this->optionsButtons[1]->UpdateText("SFX : On");
    } else {
        this->optionsButtons[1]->UpdateText("SFX : Off");
    }
};

void StateOptions::expose(){
    // Buttons
    for (auto& btn : this->optionsButtons) {
        btn->Update();
    };
    
    this->view->display(this->optionsButtons);
};