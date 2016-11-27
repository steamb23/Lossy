#include "stdafx.h"
#include "DrawManager.h"

DrawManager* DrawManager::instance;

DrawManager::DrawManager()
{
    cornflowerBlue = RGB(100, 149, 237);
    magenta = RGB(255, 0, 255);
    bgBrush = CreateSolidBrush(cornflowerBlue);
}


DrawManager::~DrawManager()
{
}

DrawManager* DrawManager::Inst()
{
    if (instance == nullptr)
        instance = new DrawManager();
    return instance;
}
