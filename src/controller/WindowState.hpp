#pragma once
#include "EnumStates.hpp"

class TowerDefense;

class WindowState
{
    protected:  
        TowerDefense* context;
    public:
        WindowState();
        virtual ~WindowState() = default;
        void setContext(TowerDefense* context);
        TowerDefense* getContext();
        virtual void init() = 0;
        virtual void expose() = 0;
};