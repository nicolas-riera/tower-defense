#pragma once
#include "../../controller/game/StateGame.hpp"

class GameWindowView {
    protected:  
        StateGame* context;
    public:
        void setContext(StateGame* context);
        virtual void init() = 0;
        virtual void display() = 0;
};