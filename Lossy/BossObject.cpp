#include "stdafx.h"
#include "BossObject.h"


BossObject::BossObject(std::shared_ptr<Game> game, std::shared_ptr<BulletManager> bulletManager)
    : GameObject(game, 50)
{

    this->bulletManager = bulletManager;
}


BossObject::~BossObject()
{
}

void BossObject::Update()
{
}

void BossObject::Draw()
{
}
