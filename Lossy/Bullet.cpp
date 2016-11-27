#include "stdafx.h"
#include "Bullet.h"
#include <Windows.h>
#include "DrawManager.h"


Bullet::Bullet(std::shared_ptr<SpriteAnimation> spriteAnimation)
{
    this->spriteAnimation = spriteAnimation;
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
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
