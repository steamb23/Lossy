#include "stdafx.h"
#include "MainScene.h"
#include "DrawManager.h"
#include "Resource.h"
#include "LossyGame.h"
#include "GameScene.h"

MainScene::MainScene(std::shared_ptr<Game> game)
    : Scene(game)
{
    bitmap1 = DrawManager::Inst()->LoadBitmapFromResource(IDB_MAINSCENE1);
    bitmap2 = DrawManager::Inst()->LoadBitmapFromResource(IDB_MAINSCENE2);

    frames = 0;
    textDraw = true;
}

MainScene::~MainScene()
{
    DeleteObject(bitmap1);
    DeleteObject(bitmap2);
}

void MainScene::Update()
{
    if (GetAsyncKeyState('Z'))
    {
        GetGame()->GetSceneManager()->ChangeScene(std::make_shared<GameScene>(GetGame()));
    }
    if (frames++ >= 30)
    {
        textDraw = !textDraw;
        frames = 0;
    }
}

void MainScene::Draw()
{
    DrawManager::Inst()->DrawBitmap(bitmap1, 0, 0, 800, 600, 0, 0, 800, 600);
    if (textDraw)
        DrawManager::Inst()->DrawBitmap(bitmap2, 0, 0, 800, 600, 0, 0, 800, 600);
}
