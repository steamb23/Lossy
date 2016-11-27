#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "SpriteAnimation.h"

class Bullet :
    public GameObject
{
    bool isDestroyed;
    std::shared_ptr<SpriteAnimation> spriteAnimation;
public:
    Bullet(std::shared_ptr<Game> game, std::shared_ptr<SpriteAnimation> spriteAnimation);
    virtual ~Bullet();

    virtual void Update();
    virtual void Draw();

    virtual void Destroy();

    bool IsDestroyed();
};

