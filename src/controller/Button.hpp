#pragma once
#include "raylib.h"
#include <functional>

class Button {
private:
    Rectangle bounds;
    const char* text;
    Color baseColor;
    Color currentColor;
    std::function<void()> onClick;

public:
    Button(float x, float y, float width, float height, const char* text, std::function<void()> callback);
    ~Button();
    void Update();
    void Draw() const;
};