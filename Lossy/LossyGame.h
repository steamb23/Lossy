#pragma once
#include "Game.h"
#include "SceneManager.h"

class LossyGame :
    public Game
{
    HBITMAP testBitmap;
public:
    LossyGame(HWND hWnd, HINSTANCE hInst);
    virtual ~LossyGame();

    virtual void Initialize();
    virtual void Update();
    virtual void Draw();
};

