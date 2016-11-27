#include "stdafx.h"
#include "LossyGame.h"
#include "Resource.h"
#include "SpriteAnimation.h"
#include "Background.h"


LossyGame::LossyGame(HWND hWnd, HINSTANCE hInst)
    :Game(hWnd, hInst)
{
}


LossyGame::~LossyGame()
{
}

std::shared_ptr<SpriteAnimation> spa;
std::shared_ptr<Background> back;

void LossyGame::Initialize()
{
    Game::Initialize();
    isFrameLimit = false;
    testBitmap = DrawManager::Inst()->LoadBitmapFromResource(IDB_BITMAPTEST);
    back = std::make_shared<Background>(shared_from_this());
    spa = std::make_shared< SpriteAnimation>(std::make_shared<Sprite>(DrawManager::Inst()->LoadBitmapFromResource(IDB_BULLET), std::vector<RECT>({ { 0,0,32,32 },{ 32,0,32,32 } })),0);
}

void LossyGame::Update()
{
    Game::Update();
    spa->Update();
    back->Update();
    this->isKey = GetAsyncKeyState(VK_UP);
}

void LossyGame::Draw()
{
    ScreenClear();
    Game::Draw();
    back->Draw();
    spa->Draw(100, 100);
    if (isKey)
        for (int i = 0; i < 1000; i++)
            DrawManager::Inst()->DrawBitmap(testBitmap, i, i*0.1, 128, 128, 0, 0, 128, 128);

    DrawFPS();
}
