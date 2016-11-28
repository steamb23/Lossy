#include "stdafx.h"
#include "Bullet.h"
#include <Windows.h>
#include "DrawManager.h"


Bullet::Bullet(std::shared_ptr<Game> game, Vector2 position, std::shared_ptr<SpriteAnimation> spriteAnimation, float radius, Vector2 velocity)
    : GameObject(game, 10)
{
    this->spriteAnimation = spriteAnimation;
    this->radius = radius;
    this->velocity = velocity;
    this->position = position;
    isDestroyed = false;
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
    XMVECTOR posTemp = XMLoadFloat2(&position);
    XMVECTOR velTemp = XMLoadFloat2(&velocity);
    posTemp += velTemp;
    XMStoreFloat2(&position, posTemp);
    spriteAnimation->Update();
}

void Bullet::Draw()
{
    int x, y;
    RECT spriteRect = spriteAnimation->GetSprite()->GetRect(spriteAnimation->GetCurrentFrame());
    x = this->position.x - spriteRect.right * 0.5;
    y = this->position.y - spriteRect.bottom * 0.5;

    spriteAnimation->Draw(x, y);
}

void Bullet::Destroy()
{
    isDestroyed = true;
}

bool Bullet::IsDestroyed()
{
    return isDestroyed;
}
