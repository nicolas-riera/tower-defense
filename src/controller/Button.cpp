#include "Button.hpp"

Button::Button(float x, float y, float width, float height, std::string text, std::function<void()> callback, TowerDefense* towerDefense)
    : bounds{ x, y, width, height }, text(text), baseColor(GRAY), currentColor(GRAY), onClick(callback), context(towerDefense) 
{
};

Button::~Button(){};

void Button::Update()
{

    if (!isActive) 
    {
        currentColor = DARKGRAY; 
        return;
    }

    Vector2 mousePos = GetMousePosition();

    if (CheckCollisionPointRec(mousePos, bounds))
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && onClick)
        {
            this->context->getSoundManager().playSfx(0);
            onClick();
            return;
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            currentColor = DARKGRAY;
        }
        else
        {
            currentColor = LIGHTGRAY;
        }
    }
    else
    {
        currentColor = baseColor;
    }
};

void Button::Draw() const
{
    DrawRectangleRec(bounds, currentColor);
    DrawRectangleLinesEx(bounds, 2, DARKGRAY);

    int fontSize = 20;
    int textWidth = MeasureText(text.c_str(), fontSize);
    
    float textX = bounds.x + (bounds.width / 2) - (textWidth / 2);
    float textY = bounds.y + (bounds.height / 2) - (fontSize / 2);
    
    DrawText(text.c_str(), textX, textY, fontSize, BLACK);
};

void Button::UpdateText(std::string text) {
    this->text = text;
};

void Button::SetActive(bool active) {
    this->isActive = active;
};

bool Button::IsActive() const {
    return this->isActive;
};