#pragma once
#include "Sprite.h"
class SpriteAnimation
{
    std::shared_ptr<Sprite> sprite;
    int interval = 0;
    int currentInterval = 0;
    int currentFrame = 0;
public:
    SpriteAnimation(std::shared_ptr<Sprite> sprite, int interval);
    SpriteAnimation(SpriteAnimation& target);
    virtual ~SpriteAnimation();

    int GetInterval() const { return interval; };
    void SetInterval(int value) { this->interval = value; };

    int GetCurrentFrame() const { return currentFrame; };

    const std::shared_ptr<Sprite> GetSprite() const
    {
        return sprite;
    }

    void Update();
    void Draw(int x, int y);
    void Draw(int x, int y, int width, int height);
};

