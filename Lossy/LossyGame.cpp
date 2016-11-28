#include "stdafx.h"
#include "LossyGame.h"
#include "Resource.h"
#include "SpriteAnimation.h"
#include "Background.h"
#include "GameScene.h"

LossyGame::LossyGame(HWND hWnd, HINSTANCE hInst)
    :Game(hWnd, hInst)
{
}


LossyGame::~LossyGame()
{
}

std::shared_ptr<SpriteAnimation> spa;

void LossyGame::Initialize()
{
    Game::Initialize();
    this->GetSceneManager()->ChangeScene(std::make_shared<GameScene>(shared_from_this()));
    // isFrameLimit = false;
    testBitmap = DrawManager::Inst()->LoadBitmapFromResource(IDB_BITMAPTEST);
    spa = std::make_shared< SpriteAnimation>(std::make_shared<Sprite>(DrawManager::Inst()->LoadBitmapFromResource(IDB_BULLET), std::vector<RECT>({ { 0,0,32,32 },{ 32,0,32,32 } })),0);
}

void LossyGame::Update()
{
    Game::Update();
    spa->Update();
}

void LossyGame::Draw()
{
    ScreenClear();
    Game::Draw();
    spa->Draw(100, 100);

    DrawFPS();
}
