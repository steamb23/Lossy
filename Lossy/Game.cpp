#include "stdafx.h"
#include "Game.h"
#include "HDCManager.h"
#include "Resource.h"

#include <string>

Game::Game(HWND hWnd, HINSTANCE hInst)
{
	this->hWnd = hWnd;
	this->hInst = hInst;
	this->gameTime = std::make_shared<GameTime>();
}


Game::~Game()
{
}

int Game::Run()
{
	TCHAR debug[10];

	OutputDebugString(TEXT("게임 실행됨."));
	OutputDebugString(EndLine);
	isRun = true;

	gameTime->Start();
	SteamB23::Stopwatch timer;
	timer.Start();

	MSG msg;
	while (isRun)
	{
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				isRun = false;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		if (timer.GetElapsedTotalSeconds() > 1 / (double)30)
		{
			PreUpdate();
			InvalidateRect(hWnd, nullptr, false);
			timer.Restart();
		}
	}
	gameTime->Stop();
	timer.Stop();
	return msg.wParam;
}

void Game::PreInitialize()
{
	testBitmap = HDCManager::Inst()->LoadBitmapFromResource(hInst, IDB_BITMAPTEST);
	Initialize();
}

void Game::PreUpdate()
{
	gameTime->Update();
	Update();
}

void Game::PreDraw()
{
	PAINTSTRUCT ps;
	HDC screenDC = BeginPaint(hWnd, &ps);

	// 더블 버퍼링 초기화.
	HBITMAP backBitmap = CreateCompatibleBitmap(screenDC, 800, 600);
	// hdc is Background DC.
	hdc = CreateCompatibleDC(screenDC);
	HBITMAP PreviousBitmap = (HBITMAP)SelectObject(hdc, backBitmap);
	memDC = CreateCompatibleDC(hdc);

	//this->graphics = std::make_shared<Gdiplus::Graphics>(hdc);
	HDCManager::Inst()->SetDC(hdc, memDC);
	Draw();
	//graphics.reset();

	DeleteDC(memDC);

	// 더블 버퍼링 종결.
	BitBlt(screenDC, 0, 0, 800, 600, hdc, 0, 0, SRCCOPY);
	SelectObject(hdc, PreviousBitmap);
	DeleteObject(backBitmap);
	DeleteDC(hdc);

	EndPaint(hWnd, &ps);
	//PAINTSTRUCT ps;
	//HDC screenDC = BeginPaint(hWnd, &ps);
	//{
	//	Gdiplus::Graphics ScreenG(screenDC);
	//	Gdiplus::Bitmap backBuffer(800, 600, &ScreenG);
	//	this->graphics = std::make_shared<Gdiplus::Graphics>(&backBuffer);


	//	Draw();


	//	ScreenG.DrawImage(&backBuffer, 0, 0);
	//	graphics.reset();
	//}
	//EndPaint(hWnd, &ps);

}

void Game::Initialize()
{
}

void Game::Update()
{
}
#include <math.h>
float a = 0;
void Game::Draw()
{
	ScreenClear();

	for (int i = 0; i < 1; i++)
		HDCManager::Inst()->DrawBitmap(testBitmap, i, i, 128, 128, 0, 0, 128, 128);

	DrawFPS();
	//ScreenClear();
	//DrawFPS();

	//Pen p(Color(255,140,0), 5);
	//graphics->DrawEllipse(&p, 100, 100, 400, 400);
	//graphics->DrawLine(&p, 300, 300, (int)(300 + cos(a) * 200), (int)(300+sin(a)*200));
	//a += 0.05f * gameTime->DeltaRatioD();

}

void Game::ScreenClear()
{
	HDCManager::Inst()->ScreenClear();
}

void Game::DrawFPS()
{
	WCHAR frame[512];

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(0, 255, 255));

	double fps = 0;
	// fps
	fps = gameTime->FPS();
	if (fps != INFINITY)
		wsprintfW(frame, L"fps : %sfps", std::to_wstring(fps).c_str());
	else
		wsprintfW(frame, L"fps : null");
	TextOut(hdc, 0, 0, frame, lstrlenW(frame));

	// deltaTime
	fps = gameTime->DeltaTimeD();
	if (fps != INFINITY)
		wsprintfW(frame, L"deltaTime : %ss", std::to_wstring(fps).c_str());
	else
		wsprintfW(frame, L"deltaTime : null");
	TextOut(hdc, 0, 20, frame, lstrlenW(frame));

	// deltaRatio
	fps = gameTime->DeltaRatioD();
	if (fps != INFINITY)
		wsprintfW(frame, L"deltaRatio : %s%%", std::to_wstring(fps * 100).c_str());
	else
		wsprintfW(frame, L"deltaRatio : null");
	TextOut(hdc, 0, 40, frame, lstrlenW(frame));
	/*
		Font font(L"Arial", 20, FontStyleRegular, UnitPixel);
		SolidBrush fontBrush(Color::White);
		graphics->DrawString(frame, lstrlenW(frame), &font, PointF(0, 0), &fontBrush);*/
}
