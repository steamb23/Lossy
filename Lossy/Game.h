#pragma once
#include <memory>
#include "GameTime.h"
#include "DrawManager.h"

class Game : protected std::enable_shared_from_this<Game>
{
public:
	Game(HWND hWnd, HINSTANCE hInst);
	virtual ~Game();

	int Run();

	void PreInitialize();
	void PreUpdate();
	void PreDraw();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw();

	void ScreenClear();
	void DrawFPS();

	BOOL IsFrameLimit() { return isFrameLimit; };
	void IsFrameLimit(BOOL value) { this->isFrameLimit = value; };
protected:
	HWND hWnd;
	HINSTANCE hInst;
	BOOL isFrameLimit;
	std::shared_ptr<GameTime> gameTime;
private:
	BOOL isRun;
};
