#include "stdafx.h"
#include "SpriteAnimation.h"


SpriteAnimation::SpriteAnimation(std::shared_ptr<Sprite> sprite, int interval)
{
    this->sprite = sprite;
    this->interval = interval;
    currentInterval = 0;
    currentFrame = 0;
}

SpriteAnimation::SpriteAnimation(SpriteAnimation & target)
    : SpriteAnimation(target.sprite, target.interval)
{
    currentFrame = rand() % target.GetSprite()->GetCount();
}

SpriteAnimation::~SpriteAnimation()
{
}

void SpriteAnimation::Update()
{
    if (++currentInterval >= interval)
    {
        currentInterval = 0;
        if (++currentFrame >= sprite->GetCount())
        {
            currentFrame = 0;
        }
    }
}

void SpriteAnimation::Draw(int x, int y)
{
    sprite->Draw(x, y, currentFrame);
}

void SpriteAnimation::Draw(int x, int y, int width, int height)
{
    sprite->Draw(x, y, width, height, currentFrame);
}
