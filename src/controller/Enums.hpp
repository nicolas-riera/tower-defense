#pragma once

enum States{
    NONE,
    MENU,
    DIFFICULTY,
    OPTIONS,
    CREDITS,
    SCOREBOARD,
    PAUSEMENU,
    GAME,
    GAMELOST,
    GAMEWON
};

enum Difficulty{
    EASY,
    MEDIUM,
    HARD
};

enum Event{
    CLICK,
    SHOOT,
    SPAWN,
    DEADINVADER,
    BUILD,
    GAMEOVER,
    SUCCESS
};