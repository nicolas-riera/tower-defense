#pragma once
#include "../controller/TowerDefense.hpp"
#include "../controller/Button.hpp"

class WindowView {
    protected:  
        TowerDefense* context;
    public:
        void setContext(TowerDefense* context);
        virtual void init() = 0;
        virtual void display(const std::vector<std::unique_ptr<Button>>& buttons) = 0;
};