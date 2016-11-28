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

    if (asdf++ % 10 == 0)
        bulletManager->CreateBullet(position, Vector2(-5, 0));

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
