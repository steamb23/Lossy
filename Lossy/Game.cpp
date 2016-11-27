#include "stdafx.h"
#include "Game.h"
#include "Resource.h"

#include <string>

Game::Game(HWND hWnd, HINSTANCE hInst)
{
    this->hWnd = hWnd;
    this->hInst = hInst;
    this->gameTime = std::make_shared<GameTime>();
    this->isFrameLimit = true;
    this->isRun = false;
    DrawManager::Inst()->SetHInst(hInst);
    this->sceneManager = std::make_shared<SceneManager>();
}


Game::~Game()
{
}

int Game::Run()
{
    isRun = true;

    gameTime->Start();
    SteamB23::Stopwatch timer;
    PreInitialize();
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
        if (!isFrameLimit || timer.GetElapsedTotalSeconds() > 1 / (double)30)
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
    HDC hdc = CreateCompatibleDC(screenDC);
    HBITMAP PreviousBitmap = (HBITMAP)SelectObject(hdc, backBitmap);
    HDC memDC = CreateCompatibleDC(hdc);

    //this->graphics = std::make_shared<Gdiplus::Graphics>(hdc);
    DrawManager::Inst()->SetDC(hdc, memDC);
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
    //    Gdiplus::Graphics ScreenG(screenDC);
    //    Gdiplus::Bitmap backBuffer(800, 600, &ScreenG);
    //    this->graphics = std::make_shared<Gdiplus::Graphics>(&backBuffer);


    //    Draw();


    //    ScreenG.DrawImage(&backBuffer, 0, 0);
    //    graphics.reset();
    //}
    //EndPaint(hWnd, &ps);

}

void Game::Initialize()
{
}

void Game::Update()
{
    this->sceneManager->Update();
}

void Game::Draw()
{
    this->sceneManager->Draw();
}

void Game::ScreenClear()
{
    DrawManager::Inst()->ScreenClear();
}

void Game::DrawFPS()
{
    WCHAR frame[512];
    HDC hdc = DrawManager::Inst()->GetDC();

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
