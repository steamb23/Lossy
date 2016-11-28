#include "stdafx.h"
#include "PlayerObject.h"
#include "Resource.h"
#include "Game.h"
#include "LossyGame.h"
#include "GameScene.h"


PlayerObject::PlayerObject(std::shared_ptr<Game> game, std::shared_ptr<BulletManager> bulletManager)
    : GameObject(game, 20)
{
    // ��������Ʈ �ʱ�ȭ
    auto sprite = std::make_shared<Sprite>(DrawManager::Inst()->LoadBitmapFromResource(IDB_PLAYER), std::vector<RECT>({ {0,0,128,128},{128,0,128,128} }));
    spriteAnimation = std::make_shared<SpriteAnimation>(sprite, 4);
    position = Vector2(100, 300);
    zKeyPressed = false;
    radius = 20;

    this->bulletManager = bulletManager;
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::Update()
{
    int speed = 8;
    if (GetAsyncKeyState(VK_UP))
    {
        position.y -= speed;
        int top = position.y - radius;
        if (top < 0)
            position.y = radius;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        position.y += speed;
        int bottom = position.y + radius;
        if (bottom > 600)
            position.y = 600 - radius;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        position.x -= speed;
        int left = position.x - radius;
        if (left < 0)
            position.x = radius;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        position.x += speed;
        int right = position.x + 100;
        if (right > 800)
            position.x = 800 - 100;
    }
    if (!zKeyPressed && GetAsyncKeyState('Z'))
    {
        bulletManager->CreateBullet(position, Vector2(40, 0));
        zKeyPressed = true;
    }
    else
    {
        zKeyPressed = false;
    }
    spriteAnimation->Update();

    auto scene = std::dynamic_pointer_cast<GameScene>(GetGame()->GetSceneManager()->GetCurrentScene());
    std::shared_ptr<Bullet> bullet;
    bullet = scene->GetEnemyBullets()->CheckCollision(shared_from_this());
    if (bullet != nullptr)
    {
        bullet->Destroy();
        scene->GetStatusBar()->SetValue(scene->GetStatusBar()->GetValue() - 0.001);
    }
}

void PlayerObject::Draw()
{
    int x = position.x - 64;
    int y = position.y - 64;
    spriteAnimation->Draw(x, y);
}
