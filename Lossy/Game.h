#pragma once
#include <memory>
#include "GdiplusException.h"
#include "GameTime.h"
class Game : std::enable_shared_from_this<Game>
{
public:
	Game(HWND hWnd, HINSTANCE hInst);
	~Game();

	int Run();

	void PreInitialize();
	void PreUpdate();
	void PreDraw();

	void Initialize();
	void Update();
	void Draw();

	void ScreenClear();
	void DrawFPS();
private:
	BOOL isRun;
	std::shared_ptr<GameTime> gameTime;

	HWND hWnd;
	HINSTANCE hInst;

	HDC hdc;
};

