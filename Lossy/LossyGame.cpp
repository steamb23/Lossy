#include "stdafx.h"
#include "LossyGame.h"
#include "Resource.h"


LossyGame::LossyGame(HWND hWnd, HINSTANCE hInst)
	:Game(hWnd, hInst)
{
}


LossyGame::~LossyGame()
{
}

void LossyGame::Initialize()
{
	isFrameLimit = false;
	testBitmap = DrawManager::Inst()->LoadBitmapFromResource(hInst, IDB_BITMAPTEST);
}

void LossyGame::Update()
{
	this->isKey = GetAsyncKeyState(VK_UP);
}

void LossyGame::Draw()
{
	ScreenClear();

	if (isKey)
		for (int i = 0; i < 2000; i++)
			DrawManager::Inst()->DrawBitmap(testBitmap, i, i*0.1, 128, 128, 0, 0, 128, 128);

	DrawFPS();
}
