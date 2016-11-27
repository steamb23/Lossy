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

	bool isKey;

	virtual void Initialize();
	virtual void Update();
	virtual void Draw();
};

