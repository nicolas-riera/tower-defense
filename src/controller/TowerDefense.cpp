#include "menu/StateMenu.hpp"
#include "menu/StateCredits.hpp"
#include "menu/StateDifficulty.hpp"
#include "menu/StatePauseMenu.hpp"
#include "game/StateGame.hpp"
#include "game/StateGameLost.hpp"
#include "game/StateGameWon.hpp"
#include "TowerDefense.hpp"
#include "EnumStates.hpp"

void TowerDefense::setState(enumStates state) {
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