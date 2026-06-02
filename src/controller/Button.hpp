#pragma once
#include "raylib.h"
#include <functional>
#include <string>

class Button {
private:
    Rectangle bounds;
    std::string text;
    Color baseColor;
    Color currentColor;
    std::function<void()> onClick;

public:
    Button(float x, float y, float width, float height, std::string text, std::function<void()> callback);
    ~Button();
    void Update();
    void Draw() const;
    void UpdateText(std::string text);
};