#include "TowerDefense.hpp"
#include "WindowState.hpp"
#include "EnumStates.hpp"

#include "menu/StateMenu.hpp"
#include "menu/StateDifficulty.hpp"
#include "menu/StateOptions.hpp"
#include "menu/StateCredits.hpp"
#include "menu/StateScoreboard.hpp"
#include "menu/StatePauseMenu.hpp"
#include "game/StateGame.hpp"
#include "game/StateGameLost.hpp"
#include "game/StateGameWon.hpp"

#include "raylib.h"

TowerDefense::TowerDefense() {};

TowerDefense::~TowerDefense() {};

void TowerDefense::setState(enumStates state)
{
    this->nextState = state;
}

void TowerDefense::updateState()
{

    if (this->nextState == NONE) return;

    switch (this->nextState)
    {
    case MENU:
        this->state = std::make_unique<StateMenu>();
        break;
    case DIFFICULTY:
        this->state = std::make_unique<StateDifficulty>();
        break;
    case OPTIONS:
        this->state = std::make_unique<StateOptions>();
        break;
    case CREDITS:
        this->state = std::make_unique<StateCredits>();
        break;
    case SCOREBOARD:
        this->state = std::make_unique<StateScoreboard>();
        break;
    case PAUSEMENU:
        this->state = std::make_unique<StatePauseMenu>();
        break;
    case GAME:
        this->state = std::make_unique<StateGame>();
        break;
    case GAMELOST:
        this->state = std::make_unique<StateGameLost>();
        break;
    case GAMEWON:
        this->state = std::make_unique<StateGameWon>();
        break;
    default:
        break;
    }
    this->state->setContext(this);
    this->state->init();

    this->nextState = NONE;
}

void TowerDefense::init()
{
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    InitWindow(this->screenWidth, this->screenHeight, "Tower Defense");

    this->soundManager = std::make_unique<SoundManager>();
    this->soundManager->playMusic(0);

    SetTargetFPS(60);

    this->setState(MENU);
};

void TowerDefense::show()
{
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        // Delayed state changing to avoid segmentation faults
        updateState();

        BeginDrawing();

            ClearBackground(RAYWHITE);

            this->state->expose();

            DrawFPS(10, 10);

        EndDrawing();
    }

    this->state.reset(); 

    CloseWindow();
};