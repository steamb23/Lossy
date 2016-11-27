#include "stdafx.h"
#include "LossyGame.h"
#include "Resource.h"
#include "SpriteAnimation.h"


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
	// isFrameLimit = false;
	testBitmap = DrawManager::Inst()->LoadBitmapFromResource(hInst, IDB_BITMAPTEST);
	spa = std::make_shared< SpriteAnimation>(std::make_shared<Sprite>(DrawManager::Inst()->LoadBitmapFromResource(hInst, IDB_BULLET), std::vector<RECT>({ { 0,0,32,32 },{ 32,0,32,32 } })),0);
}

void LossyGame::Update()
{
	spa->Update();
	this->isKey = GetAsyncKeyState(VK_UP);
}

void LossyGame::Draw()
{
	ScreenClear();
	spa->Draw(100, 100);
	if (isKey)
		for (int i = 0; i < 2000; i++)
			DrawManager::Inst()->DrawBitmap(testBitmap, i, i*0.1, 128, 128, 0, 0, 128, 128);

	DrawFPS();
}
