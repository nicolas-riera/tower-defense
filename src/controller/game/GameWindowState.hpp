#pragma once

class StateGame;

class GameWindowState
{
    protected:  
        StateGame* context;
    public:
        GameWindowState();
        virtual ~GameWindowState() = default;
        void setContext(StateGame* context);
        StateGame* getContext();
        virtual void init() = 0;
        virtual void expose() = 0;
};