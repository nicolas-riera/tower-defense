#pragma once
#include <memory>
#include "SoundManager.hpp"
#include "Enums.hpp"
#include "WindowState.hpp"
#include "../model/PersistentDataModel.hpp"

class TowerDefense
{
    private:
        PersistentDataModel dataModel;
        std::unique_ptr<WindowState> state;
        std::unique_ptr<SoundManager> soundManager;
        States nextState;
    public:
        const int screenWidth = 1280;
        const int screenHeight = 720;
        Difficulty difficulty = EASY;
        TowerDefense();
        ~TowerDefense();
        void updateState();
        void setState(States state);
        SoundManager& getSoundManager();
        void init();
        void show();
};
