#include "StateGameView.hpp"

StateGameView::StateGameView(){};

StateGameView::~StateGameView(){};

void StateGameView::init(){};

void StateGameView::display(const std::vector<std::unique_ptr<Button>>& buttons) {
    return;
}

void StateGameView::display(const GridMatrix& grid){
    int tileSize = 80;

    for (size_t row = 0; row < grid.size(); ++row) {
        for (size_t col = 0; col < grid[row].size(); ++col) {
            
            int posX = col * tileSize;
            int posY = row * tileSize;
            Color tileColor = GRAY;

            switch (grid[row][col]) {
                case 0: 
                    tileColor = DARKGRAY;
                    break; 
                case 1:
                    tileColor = GREEN;
                    break; 
                case 2:
                    tileColor = LIGHTGRAY;
                    break; 
                case 3:
                    tileColor = ORANGE;
                    break; 
                case 4:
                    tileColor = RED;
                    break; 
                default:
                    tileColor = WHITE;
                    break;
            }

            DrawRectangle(posX, posY, tileSize - 1, tileSize - 1, tileColor);
        }
    }
};