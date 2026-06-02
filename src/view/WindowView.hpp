#pragma once
#include "../controller/TowerDefense.hpp"
#include "../controller/Button.hpp"

class WindowView {
    protected:  
        TowerDefense* context;
    public:
        void setContext(TowerDefense* context);
        virtual void init() = 0;
        virtual void display(std::vector<Button> buttons) = 0;
};