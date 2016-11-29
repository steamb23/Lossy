#include "stdafx.h"
#include "LossyGame.h"
#include "Resource.h"
#include "SpriteAnimation.h"
#include "Background.h"
#include "GameScene.h"
#include <time.h>

LossyGame::LossyGame(HWND hWnd, HINSTANCE hInst)
    :Game(hWnd, hInst)
{
    srand(time(0));
}


LossyGame::~LossyGame()
{
}

void LossyGame::Initialize()
{
    Game::Initialize();
    this->GetSceneManager()->ChangeScene(std::make_shared<GameScene>(shared_from_this()));
    // isFrameLimit = false;
    testBitmap = DrawManager::Inst()->LoadBitmapFromResource(IDB_BITMAPTEST);
}

void LossyGame::Update()
{
    Game::Update();
}

void LossyGame::Draw()
{
    ScreenClear();
    Game::Draw();

    DrawFPS();
}
