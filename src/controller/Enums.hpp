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
    WAIT,
    RUNNING,
    RUNNINGSHOP,
    PAUSEMENU,
    GAMELOST,
    GAMEWON
};

enum TowerSelection{
    EMPTY,
    SMALLTOWER,
    BIGTOWER
};

enum InvaderSelection{
    NOBODY,
    SMALLINVADER,
    BIGINVADER,
    BOSSINVADER
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