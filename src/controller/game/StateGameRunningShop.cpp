#include "StateGameRunningShop.hpp"
#include <iostream>

void StateGameRunningShop::init(){
    StateGameRunningBase::init();

    this->view = std::make_unique<StateGameRunningShopView>();
    this->view->init();
    this->view->setContext(this->context);        
};

void StateGameRunningShop::expose(){
    StateGameRunningBase::expose();

    const auto& grid = this->context->getGrid(); 
    float windowWidth = this->context->getContext()->screenWidth;
    float windowHeight = this->context->getContext()->screenHeight;

    this->view->display(grid, windowWidth, windowHeight);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !grid.empty() && !grid[0].empty()) {
        Vector2 mousePos = GetMousePosition();

        float baseTileSize = 128.0f;
        float finalScale = ((windowWidth / (grid[0].size() * baseTileSize)) < (windowHeight / (grid.size() * baseTileSize))) 
                           ? (windowWidth / (grid[0].size() * baseTileSize)) 
                           : (windowHeight / (grid.size() * baseTileSize));
        float scaledTileSize = baseTileSize * finalScale;

        float offsetX = (windowWidth - (grid[0].size() * scaledTileSize)) / 2.0f;
        float offsetY = (windowHeight - (grid.size() * scaledTileSize)) / 2.0f;

        int col = static_cast<int>((mousePos.x - offsetX) / scaledTileSize);
        int row = static_cast<int>((mousePos.y - offsetY) / scaledTileSize);

        if (col >= 0 && col < static_cast<int>(grid[0].size()) &&
            row >= 0 && row < static_cast<int>(grid.size() - 1)) {
            
            if (grid[row][col] == 1) {

                for (const auto& tower : this->context->getTowers()) {
                    if (tower->getXMatrix() == static_cast<short>(col) && tower->getYMatrix() == static_cast<short>(row)) {
                        return; 
                    }
                }

                this->context->placeTower(static_cast<short>(col), static_cast<short>(row));

                this->context->selectedTower = EMPTY;
                this->context->setState(RUNNING);
            }
        }
    }
};