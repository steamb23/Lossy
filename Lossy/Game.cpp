#include "stdafx.h"
#include "Game.h"
#include "HDCManager.h"

using namespace Gdiplus;


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
		if (timer.GetElapsedTotalSeconds() > 1 / (float)30)
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
	HDC memDC = CreateCompatibleDC(screenDC);

	//this->graphics = std::make_shared<Gdiplus::Graphics>(hdc);

	Draw();
	//graphics.reset();

	DeleteDC(memDC);

	// 더블 버퍼링 종결.
	BitBlt(screenDC, 0, 0, 800, 600, hdc, 0, 0, SRCCOPY);
	SelectObject(hdc, PreviousBitmap);
	DeleteObject(backBitmap);
	DeleteDC(memDC);
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
	HDCManager::Inst()->ScreenClear(hdc);
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
	//SolidBrush bgBrush(Gdiplus::Color::Black);
	//graphics->FillRectangle(&bgBrush, 0, 0, 800, 600);
}

void Game::DrawFPS()
{
	WCHAR frame[512];
	double fps = 0;
	fps = gameTime->FPS();
	if (fps != INFINITY)
		wsprintfW(frame, L"fps : %d", (int)(fps + 0.5));
	else
	{
		wsprintfW(frame, L"fps : 0");
	}

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(255, 0, 0));
	TextOut(hdc, 0, 0, frame, lstrlenW(frame));
/*
	Font font(L"Arial", 20, FontStyleRegular, UnitPixel);
	SolidBrush fontBrush(Color::White);
	graphics->DrawString(frame, lstrlenW(frame), &font, PointF(0, 0), &fontBrush);*/
}
