#include "StateGameView.hpp"

StateGameView::StateGameView(){};

StateGameView::~StateGameView() {
    // Grid
    UnloadTexture(textureBackground);
    UnloadTexture(textureBlank);
    UnloadTexture(textureWall);
    UnloadTexture(texturePath);
    UnloadTexture(textureStart);
    UnloadTexture(textureEnd);
};

void StateGameView::init() {
    // Grid
    textureBackground = LoadTexture("assets/img/grid/bg.png");
    textureBlank = LoadTexture("assets/img/grid/blank.png");
    textureWall = LoadTexture("assets/img/grid/wall.png");
    texturePath = LoadTexture("assets/img/grid/path.png");
    textureStart = LoadTexture("assets/img/grid/start.png");
    textureEnd = LoadTexture("assets/img/grid/end.png");
};

void StateGameView::display(const ButtonsVector& buttons) {
    return;
};

void StateGameView::display(const GridMatrix& grid, const GameStats& gameStats) {

    // Background drawing
    DrawTexture(textureBackground, 0, 0, WHITE);

    // Grid drawing
    if (grid.empty() || grid[0].empty()) return;

    float baseTileSize = 128.0f;
    float windowWidth = this->context->screenWidth;
    float windowHeight = this->context->screenHeight;

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
                    currentTexture = textureBlank;
                    break;
            }

            DrawTextureEx(currentTexture, Vector2{posX, posY}, 0.0f, finalScale, WHITE);
        }
    }

    // UI drawing

    std::string scoreText = "Score: " + std::to_string(gameStats.score);
    std::string balanceText = "Gold: " + std::to_string(gameStats.balance);
    std::string waveText = "Wave: " + std::to_string(gameStats.wavecounter);

    std::string fullStatsStr = scoreText + "   |   " + balanceText + "   |   " + waveText;

    int posX = 30;
    int posY = 675; 
    int fontSize = 24;

    // Text shadow drawing
    DrawText(fullStatsStr.c_str(), posX + 2, posY + 2, fontSize, BLACK);
    DrawText(fullStatsStr.c_str(), posX, posY, fontSize, RAYWHITE);
};