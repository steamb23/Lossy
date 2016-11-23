#pragma once
#include <memory>
#include "GdiplusException.h"
#include "GameTime.h"
class Game : std::enable_shared_from_this<Game>
{
public:
	Game(HWND hWnd);
	~Game();

	int Run();

	void PreUpdate();
	void PreDraw();

	void Update();
	void Draw();

	void ScreenClear();
	void DrawFPS();
private:
	BOOL isRun;
	std::shared_ptr<GameTime> gameTime;

	HWND hWnd;
	ULONG_PTR gpToken;

	std::shared_ptr<Gdiplus::Graphics> graphics;
};

