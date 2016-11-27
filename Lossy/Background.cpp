#include "stdafx.h"
#include "Background.h"
#include "DrawManager.h"
#include "Game.h"
#include "Resource.h"

Background::Background(std::shared_ptr<Game> game)
{
    // 시간 관계상 생성자에 때려박는다.
    this->background1 = DrawManager::Inst()->LoadBitmapFromResource(IDB_BACKGROUND1);
    this->background2 = DrawManager::Inst()->LoadBitmapFromResource(IDB_BACKGROUND2);
    x1 = 0;
    x2 = 0;

    this->game = game;
}


Background::~Background()
{
}

void Background::Update()
{
    auto deltaRatio = game->GetGameTime()->DeltaRatio();
    x1 -= 4 * deltaRatio;
    if (x1 < -800)
        x1 += 800;

    x2 -= 32 * deltaRatio;
    if (x2 < -800)
        x2 += 800;
}

void Background::Draw()
{
    auto dm = DrawManager::Inst();
    int x1 = this->x1;
    x1 -= x1 % 2;
    int x2 = this->x2;
    x2 -= x2 % 2;
    dm->DrawBitmap(background1, x1, 0, 800, 600, 0, 0, 800, 600);
    dm->DrawBitmap(background1, x1 + 800, 0, 800, 600, 0, 0, 800, 600);
    dm->DrawBitmap(background2, x2, 0, 800, 600, 0, 0, 800, 600);
    dm->DrawBitmap(background2, x2 + 800, 0, 800, 600, 0, 0, 800, 600);
}
