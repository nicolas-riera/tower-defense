#include "Button.hpp"

Button::Button(float x, float y, float width, float height, const char* text, std::function<void()> callback)
    : bounds{ x, y, width, height }, text(text), baseColor(GRAY), currentColor(GRAY), onClick(callback) 
{
};

Button::~Button(){};

void Button::Update()
{
    Vector2 mousePos = GetMousePosition();

    if (CheckCollisionPointRec(mousePos, bounds))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            currentColor = MAROON;
        }
        else
        {
            currentColor = LIGHTGRAY;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && onClick)
        {
            onClick();
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
    int textWidth = MeasureText(text, fontSize);
    
    float textX = bounds.x + (bounds.width / 2) - (textWidth / 2);
    float textY = bounds.y + (bounds.height / 2) - (fontSize / 2);
    
    DrawText(text, textX, textY, fontSize, BLACK);
};