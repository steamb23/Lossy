#include "stdafx.h"
#include "BossObject.h"
#include "Resource.h"
#include "LossyGame.h"
#include "GameScene.h"


BossObject::BossObject(std::shared_ptr<Game> game, std::shared_ptr<BulletManager> bulletManager)
    : GameObject(game, 50)
{
    auto sprite = std::make_shared<Sprite>(DrawManager::Inst()->LoadBitmapFromResource(IDB_BOSS), std::vector<RECT>({ { 0,0,256,256 },{ 256,0,256,256 },{ 512,0,256,256 } }));
    spriteAnimation = std::make_shared<SpriteAnimation>(sprite, 4);
    position = Vector2(600, 300);
    radius = 100;

    this->bulletManager = bulletManager;
}


BossObject::~BossObject()
{
}
int asdf = 0;
void BossObject::Update()
{
    spriteAnimation->Update();

    Shot();

    auto scene = std::dynamic_pointer_cast<GameScene>(GetGame()->GetSceneManager()->GetCurrentScene());
    std::shared_ptr<Bullet> bullet;
    bullet = scene->GetPlayerBullets()->CheckCollision(shared_from_this());
    if (bullet != nullptr)
    {
        bullet->Destroy();
        scene->GetStatusBar()->SetValue(scene->GetStatusBar()->GetValue() - 0.001);
    }
}

void BossObject::Draw()
{
    int x = position.x - 128;
    int y = position.y - 128;
    spriteAnimation->Draw(x, y);
}

void BossObject::Shot()
{
    // 플레이어 각도 구하기
    auto scene = std::dynamic_pointer_cast<GameScene>(GetGame()->GetSceneManager()->GetCurrentScene());
    XMVECTOR playervec = XMLoadFloat2(&scene->GetPlayerObject()->GetPosition());
    XMVECTOR bossvec = XMLoadFloat2(&this->GetPosition());

    XMVECTOR relativeVec = playervec - bossvec;

    float angle = atan2(XMVectorGetY(relativeVec), XMVectorGetX(relativeVec));

    static int shotTime = 0;
    static int pattern = 0;
    
    if (shotTime++ > 30)
    {
        switch (pattern)
        {
        case 0:
            if (ShotPattern1(angle))
                shotTime = -30;
            break;
        }
    }
}
#define LEFTANGLE 180
bool BossObject::ShotPattern1(float angle)
{
    static int patternLoopCount = 0;
    static int interval = 0;

    if (interval++ % 20 == 0)
    {
        bulletManager->CreateBullet(position, angle - 0.8, 8);
        bulletManager->CreateBullet(position, angle - 0.4, 8);
        bulletManager->CreateBullet(position, angle, 8);
        bulletManager->CreateBullet(position, angle + 0.4, 8);
        bulletManager->CreateBullet(position, angle + 0.8, 8);
        patternLoopCount++;
    }
    if (patternLoopCount > 10)
    {
        interval = 0;
        patternLoopCount = 0;
        return true;
    }
    else
    {
        return false;
    }
}