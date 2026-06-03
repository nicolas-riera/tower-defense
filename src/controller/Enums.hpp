#pragma once

enum States{
    NONE,
    MENU,
    DIFFICULTY,
    OPTIONS,
    CREDITS,
    SCOREBOARD,
    GAME
};

enum Difficulty{
    EASY,
    NORMAL,
    HARD
};

enum GameStates{
    RUNNING,
    PAUSEMENU,
    GAMELOST,
    GAMEWON
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