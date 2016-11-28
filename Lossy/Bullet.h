#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "SpriteAnimation.h"

class Bullet :
    public GameObject
{
    bool isDestroyed;
    std::shared_ptr<SpriteAnimation> spriteAnimation;
    Vector2 velocity;
    float radius;
public:
    Bullet(std::shared_ptr<Game> game, Vector2 position, std::shared_ptr<SpriteAnimation> spriteAnimation, float radius, Vector2 velocity);
    virtual ~Bullet();

    virtual void Update();
    virtual void Draw();

    virtual void Destroy();

    bool IsDestroyed();
};

