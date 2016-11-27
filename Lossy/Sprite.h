#pragma once
#include <memory>
#include <Windows.h>
#include <vector>
#include "DrawManager.h"
class Sprite : std::enable_shared_from_this<Sprite>
{
    HBITMAP bitmap;
    std::vector<RECT> sourceRect;
public:
    Sprite(HBITMAP bitmap, std::vector<RECT> point);
    virtual ~Sprite();

    int GetCount() { return sourceRect.size(); };
    RECT GetRect(int index)
    {
        return sourceRect[index];
    }

    void Draw(int x, int y, int sourceRectIndex);
    void Draw(int x, int y, RECT sourceRect);
    void Draw(int x, int y, int width, int height, int sourceRectIndex);
    void Draw(int x, int y, int width, int height, RECT sourceRect);
    void Draw(int dest_x, int dest_y, int dest_width, int dest_height, int source_x, int source_y, int source_width, int source_height);
};

