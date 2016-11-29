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
    isBerserk = false;

    this->bulletManager = bulletManager;
}


BossObject::~BossObject()
{
}
int asdf = 0;
void BossObject::Update()
{
    static float berserkTime = 0;

    spriteAnimation->Update();

    Shot();

    auto scene = std::dynamic_pointer_cast<GameScene>(GetGame()->GetSceneManager()->GetCurrentScene());
    std::shared_ptr<Bullet> bullet;
    bullet = scene->GetPlayerBullets()->CheckCollision(shared_from_this());
    float hp = scene->GetStatusBar()->GetValue();
    if (bullet != nullptr)
    {
        bullet->Destroy();
        scene->GetStatusBar()->SetValue(hp - 0.001);
        if (hp < 0.1)
        {
            isBerserk = true;
        }

    }
    if (isBerserk)
    {
        BerserkPattern();
        berserkTime += 0.05;
        hp = scene->GetStatusBar()->GetValue();
        scene->GetStatusBar()->SetValue(hp + 0.00005);

        position.y = 300 + sin(berserkTime) * 200;
        if (hp > 0.2)
            isBerserk = false;
    }
    else if (position.y != 300)
    {
        berserkTime = 0;
        position.y += (300 - position.y)*0.05 ;
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

    static int shotTime = -30;
    static int pattern = rand() % 4;

    if (shotTime++ > 30)
    {
        switch (pattern)
        {
        case 0:
            if (ShotPattern1(angle))
            {
                shotTime = -30;
                pattern = rand() % 4;
            }
            break;
        case 1:
            if (ShotPattern2(angle))
            {
                shotTime = -30;
                pattern = rand() % 4;
            }
            break;
        case 2:
            if (ShotPattern3(angle))
            {
                shotTime = -30;
                pattern = rand() % 4;
            }
            break;
        case 3:
            if (ShotPattern4(angle))
            {
                shotTime = -30;
                pattern = rand() % 4;
            }
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

bool BossObject::ShotPattern2(float angle)
{
    static int interval = 0;
    static int shotCount = 0;
    static int patternLoopCount = 0;

    if (interval >= 0 && interval % 2 == 0)
    {
        if (patternLoopCount % 2 == 0)
            bulletManager->CreateBullet(position, angle - (shotCount - 5) * 0.02, 5 + shotCount);
        else
            bulletManager->CreateBullet(position, angle + (shotCount - 5) * 0.02, 5 + shotCount);
        shotCount++;
    }
    interval++;
    if (shotCount > 8)
    {
        interval = -30;
        shotCount = 0;
        patternLoopCount++;
    }
    if (patternLoopCount > 5)
    {
        interval = 0;
        shotCount = 0;
        patternLoopCount = 0;
        return true;
    }
    else
    {
        return false;
    }
}

bool BossObject::ShotPattern3(float angle)
{
    static int patternLoopCount = 0;
    static int interval = 0;

    if (interval++ % 15 == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            bulletManager->CreateBullet(position, patternLoopCount * 13 + i*(360 / 10), 6, false);
        }
        patternLoopCount++;
    }
    if (patternLoopCount > 40)
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

bool BossObject::ShotPattern4(float angle)
{
    static int patternLoopCount = 0;
    static int interval = 0;
    interval++;
    bulletManager->CreateBullet(position, rand(), 10, false);
    patternLoopCount++;
    if (patternLoopCount > 300)
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

void BossObject::BerserkPattern()
{
    static int interval = 0;
    if (interval++ % 3 == 0)
    {
        bulletManager->CreateBullet(position, rand(), rand() / RAND_MAX * 10 + 5, false);
    }
}
