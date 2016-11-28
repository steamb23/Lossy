#include "stdafx.h"
#include "BossObject.h"
#include "Resource.h"
#include "LossyGame.h"


BossObject::BossObject(std::shared_ptr<Game> game, std::shared_ptr<BulletManager> bulletManager)
    : GameObject(game, 50)
{
    auto sprite = std::make_shared<Sprite>(DrawManager::Inst()->LoadBitmapFromResource(IDB_BOSS), std::vector<RECT>({ { 0,0,256,256 },{ 256,0,256,256 },{ 512,0,256,256 } }));
    spriteAnimation = std::make_shared<SpriteAnimation>(sprite, 4);
    position = Vector2(600, 300);
    radius = 20;
    this->game = std::dynamic_pointer_cast<LossyGame>(game);

    this->bulletManager = bulletManager;
}


BossObject::~BossObject()
{
}

void BossObject::Update()
{
    spriteAnimation->Update();
}

void BossObject::Draw()
{
    int x = position.x - 128;
    int y = position.y - 128;
    spriteAnimation->Draw(x, y);
}
