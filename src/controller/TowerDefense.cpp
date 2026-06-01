#include "TowerDefense.hpp"
#include "WindowState.hpp"
#include "EnumStates.hpp"

#include "menu/StateMenu.hpp"
#include "menu/StateCredits.hpp"
#include "menu/StateDifficulty.hpp"
#include "menu/StatePauseMenu.hpp"
#include "game/StateGame.hpp"
#include "game/StateGameLost.hpp"
#include "game/StateGameWon.hpp"

#include "raylib.h"

TowerDefense::TowerDefense(){};

TowerDefense::~TowerDefense(){};

void TowerDefense::setState(enumStates state)
{
    switch (state)
    {
    case MENU:
        this->state = std::make_unique<StateMenu>();
        break;
    case CREDITS:
        this->state = std::make_unique<StateCredits>();
        break;
    case DIFFICULTY:
        this->state = std::make_unique<StateDifficulty>();
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
}

void TowerDefense::init()
{
    this->state = std::make_unique<StateMenu>();

    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Tower Defense");

    SetTargetFPS(60); 
    SetWindowMinSize(screenWidth, screenHeight);
    SetWindowMaxSize(screenWidth, screenHeight);
};

void TowerDefense::show()
{
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        this->state;

        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();
};