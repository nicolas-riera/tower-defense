#include "StateGameRunningShopView.hpp"

StateGameRunningShopView::StateGameRunningShopView(){};

StateGameRunningShopView::~StateGameRunningShopView(){};

void StateGameRunningShopView::init() {};

void StateGameRunningShopView::display(const ButtonsVector& buttons){};

void StateGameRunningShopView::display(const GridMatrix& grid, float windowWidth, float windowHeight) {
    if (grid.empty() || grid[0].empty()) return;

    float baseTileSize = 128.0f;
    float gridWidth = grid[0].size() * baseTileSize;
    float gridHeight = grid.size() * baseTileSize;

    float scaleX = windowWidth / gridWidth;
    float scaleY = windowHeight / gridHeight;
    float finalScale = (scaleX < scaleY) ? scaleX : scaleY;
    float scaledTileSize = baseTileSize * finalScale;

    float offsetX = (windowWidth - (grid[0].size() * scaledTileSize)) / 2.0f;
    float offsetY = (windowHeight - (grid.size() * scaledTileSize)) / 2.0f;

    Vector2 mousePos = GetMousePosition();

    for (size_t row = 0; row < grid.size() - 1; ++row) {
        for (size_t col = 0; col < grid[row].size(); ++col) {
            
            float posX = offsetX + (static_cast<float>(col) * scaledTileSize);
            float posY = offsetY + (static_cast<float>(row) * scaledTileSize);

            if (mousePos.x >= posX && mousePos.x < posX + scaledTileSize &&
                mousePos.y >= posY && mousePos.y < posY + scaledTileSize) {

                bool validCell = (grid[row][col] == 1);
                
                for (const auto& tower : this->context->getTowers()) {
                    if (tower->getXMatrix() == static_cast<short>(col) && tower->getYMatrix() == static_cast<short>(row)) {
                        validCell = false;
                        break; 
                    }
                }
                
                Color overlayColor = validCell ? GREEN : RED;
                
                DrawRectangleV(Vector2{posX, posY}, Vector2{scaledTileSize, scaledTileSize}, Fade(overlayColor, 0.4f));
                
                return;
            }
        }
    }
};

