#include "StateGameView.hpp"

StateGameView::StateGameView(){};

StateGameView::~StateGameView() {
    // Grid
    UnloadTexture(textureWall);
    UnloadTexture(textureBlank);
    UnloadTexture(texturePath);
    UnloadTexture(textureStart);
    UnloadTexture(textureEnd);
};

void StateGameView::init() {
    // Grid
    textureWall = LoadTexture("assets/img/grid/wall.png");
    textureBlank = LoadTexture("assets/img/grid/blank.png");
    texturePath = LoadTexture("assets/img/grid/path.png");
    textureStart = LoadTexture("assets/img/grid/start.png");
    textureEnd = LoadTexture("assets/img/grid/end.png");
};

void StateGameView::display(const std::vector<std::unique_ptr<Button>>& buttons) {
    return;
};

void StateGameView::display(const GridMatrix& grid) {
    if (grid.empty() || grid[0].empty()) return;

    float baseTileSize = 128.0f;
    // Temp, edit to get data from context
    float windowWidth = 1280.0f;
    float windowHeight = 720.0f;

    float gridWidth = grid[0].size() * baseTileSize;
    float gridHeight = grid.size() * baseTileSize;

    float scaleX = windowWidth / gridWidth;
    float scaleY = windowHeight / gridHeight;
    float finalScale = (scaleX < scaleY) ? scaleX : scaleY;

    float scaledTileSize = baseTileSize * finalScale;

    float offsetX = (windowWidth - (grid[0].size() * scaledTileSize)) / 2.0f;
    float offsetY = (windowHeight - (grid.size() * scaledTileSize)) / 2.0f;

    for (size_t row = 0; row < grid.size(); ++row) {
        for (size_t col = 0; col < grid[row].size(); ++col) {
            
            float posX = offsetX + (static_cast<float>(col) * scaledTileSize);
            float posY = offsetY + (static_cast<float>(row) * scaledTileSize);
            
            Texture2D currentTexture;

            switch (grid[row][col]) {
                case 0: 
                    currentTexture = textureWall;
                    break; 
                case 1:
                    currentTexture = textureBlank;
                    break; 
                case 2:
                    currentTexture = texturePath;
                    break; 
                case 3:
                    currentTexture = textureStart;
                    break; 
                case 4:
                    currentTexture = textureEnd;
                    break; 
                default:
                    currentTexture = textureWall;
                    break;
            }

            DrawTextureEx(currentTexture, Vector2{posX, posY}, 0.0f, finalScale, WHITE);
        }
    }
};