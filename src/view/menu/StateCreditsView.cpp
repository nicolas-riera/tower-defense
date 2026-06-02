#include "StateCreditsView.hpp"

StateCreditsView::StateCreditsView(){};

StateCreditsView::~StateCreditsView(){
    UnloadTexture(this->background);
    UnloadTexture(this->arthur_pfp);
    UnloadTexture(this->nicolas_pfp);
};

void StateCreditsView::init(){
    this->background = LoadTexture("assets/img/menu_background.png");
    this->arthur_pfp = LoadTexture("assets/img/pfp/arthur.png");
    this->nicolas_pfp = LoadTexture("assets/img/pfp/nicolas.png");
};

void StateCreditsView::display(const std::vector<std::unique_ptr<Button>>& buttons){
    DrawTextureEx(this->background, { 0.0f, 0.0f }, 0, 1, WHITE);

    DrawText("CREDITS", (this->context->screenWidth / 2) - 72, 130, 32, BLACK);

    Rectangle nicolasBox = { 260.0f, 400.0f, 360.0f, 90.0f };
    Rectangle arthurBox = { 660.0f, 400.0f, 360.0f, 90.0f };

    float imageScale = 0.35f;
    float verticalPosition = 210.0f;


    DrawTextureEx(this->nicolas_pfp, { 350.0f, verticalPosition }, 0.0f, imageScale, WHITE);
    DrawTextureEx(this->arthur_pfp, { 750.0f, verticalPosition }, 0.0f, imageScale, WHITE);

    DrawRectangleRec(nicolasBox, LIGHTGRAY);
    DrawRectangleLinesEx(nicolasBox, 2, GRAY);

    DrawRectangleRec(arthurBox, LIGHTGRAY);
    DrawRectangleLinesEx(arthurBox, 2, GRAY);

    const char* nameNic = "Nicolas";
    const char* linkNic = "github.com/nicolas-riera/";
    int wNameNic = MeasureText(nameNic, 24);
    int wLinkNic = MeasureText(linkNic, 18);
    DrawText(nameNic, nicolasBox.x + (nicolasBox.width - wNameNic) / 2, nicolasBox.y + 15, 24, BLACK);
    DrawText(linkNic, nicolasBox.x + (nicolasBox.width - wLinkNic) / 2, nicolasBox.y + 50, 18, DARKGRAY);

    const char* nameArt = "Arthur";
    const char* linkArt = "github.com/arthur-georget";
    int wNameArt = MeasureText(nameArt, 24);
    int wLinkArt = MeasureText(linkArt, 18);
    DrawText(nameArt, arthurBox.x + (arthurBox.width - wNameArt) / 2, arthurBox.y + 15, 24, BLACK);
    DrawText(linkArt, arthurBox.x + (arthurBox.width - wLinkArt) / 2, arthurBox.y + 50, 18, DARKGRAY);

    for (auto& btn : buttons) {
        btn->Draw();
    };
};