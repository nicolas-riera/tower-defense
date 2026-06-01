#pragma once
#include "../controller/TowerDefense.hpp"

class WindowView {
    protected:  
        TowerDefense* context;
    public:
        void setContext(TowerDefense* context);
        virtual void init() = 0;
        virtual void display() = 0;
};