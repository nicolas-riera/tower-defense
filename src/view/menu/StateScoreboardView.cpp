#include "StateScoreboardView.hpp"
#include <string>
#include <algorithm>

StateScoreboardView::StateScoreboardView(){};

StateScoreboardView::~StateScoreboardView(){
    UnloadTexture(this->background);
};

void StateScoreboardView::init(){
    this->background = LoadTexture("assets/img/menu_background.png");
};

void StateScoreboardView::display(const std::vector<std::unique_ptr<Button>>& buttons) {
    std::vector<PersistentDataModel::PlayerScore> emptyScores;
    this->display(buttons, emptyScores, 0.0f);
}

void StateScoreboardView::display(const std::vector<std::unique_ptr<Button>>& buttons, const std::vector<PersistentDataModel::PlayerScore>& scores, float scrollOffset){
    DrawTextureEx(this->background, { 0.0f, 0.0f }, 0, 1, WHITE);

    DrawText("Scoreboard", (this->context->screenWidth / 2) - 90, 100, 32, BLACK);

    Rectangle tableBox = { 300.0f, 180.0f, 680.0f, 320.0f };
    float rowHeight = 40.0f;
    float padding = 10.0f;
    float maxUsernameWidth = 240.0f; 

    DrawRectangleRec(tableBox, LIGHTGRAY);
    DrawRectangleLinesEx(tableBox, 2, GRAY);

    BeginScissorMode((int)tableBox.x, (int)tableBox.y, (int)tableBox.width, (int)tableBox.height);

        for (size_t i = 0; i < scores.size(); i++) {
            float itemY = tableBox.y + (i * rowHeight) + scrollOffset;

            if (itemY + rowHeight < tableBox.y || itemY > tableBox.y + tableBox.height) {
                continue;
            }

            Color rowColor = (i % 2 == 0) ? RAYWHITE : WHITE;
            DrawRectangle(tableBox.x + 2, itemY, tableBox.width - 4, rowHeight - 2, rowColor);

            std::string displayName = scores[i].username;
            if (MeasureText(displayName.c_str(), 20) > maxUsernameWidth) {
                while (!displayName.empty() && MeasureText((displayName + "...").c_str(), 20) > maxUsernameWidth) {
                    displayName.pop_back();
                }
                displayName += "...";
            }

            std::string diffStr = "Unknown";
            switch (scores[i].difficulty) {
                case 0: diffStr = "Easy"; break;
                case 1: diffStr = "Normal"; break;
                case 2: diffStr = "Hard"; break;
            }

            std::string diffText = "Diff: " + diffStr;
            std::string scoreText = "Score: " + std::to_string(scores[i].score);
            
            DrawText(displayName.c_str(), tableBox.x + padding, itemY + 10, 20, BLACK);
            DrawText(diffText.c_str(), tableBox.x + 280, itemY + 10, 18, DARKGRAY);
            DrawText(scoreText.c_str(), tableBox.x + 480, itemY + 10, 18, BLACK);
        }

    EndScissorMode();

    for (auto& btn : buttons) {
        btn->Draw();
    };
}