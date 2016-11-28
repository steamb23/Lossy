#include "stdafx.h"
#include "PlayerObject.h"
#include "Resource.h"
#include "Game.h"


PlayerObject::PlayerObject(std::shared_ptr<Game> game)
    : GameObject(game)
{
    // 스프라이트 초기화
    auto sprite = std::make_shared<Sprite>(DrawManager::Inst()->LoadBitmapFromResource(IDB_PLAYER), std::vector<RECT>({ {0,0,128,128},{128,0,128,128} }));
    spriteAnimation = std::make_shared<SpriteAnimation>(sprite, 4);
    position = Vector2(100,300);
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::Update()
{
    int speed = 5;
    if (GetAsyncKeyState(VK_UP))
    {
        position.y -= speed;
        int top = position.y - 40;
        if (top < 0)
            position.y = 40;
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        position.y += speed;
        int bottom = position.y + 40;
        if (bottom > 600)
            position.y = 600 - 40;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        position.x -= speed;
        int left = position.x - 40;
        if (left < 0)
            position.x = 40;
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        position.x += speed;
        int right = position.x + 40;
        if (right > 800)
            position.x = 800 - 40;
    }
    spriteAnimation->Update();
}

void PlayerObject::Draw()
{
    int x = position.x - 64;
    int y = position.y - 64;
    spriteAnimation->Draw(x, y);
}
