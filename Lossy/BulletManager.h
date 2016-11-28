#pragma once
#include <list>
#include "Bullet.h"
#include "SpriteAnimation.h"
class BulletManager
{
    std::weak_ptr<Game> game;

    std::list<std::shared_ptr<Bullet>> bulletList;

    std::shared_ptr<SpriteAnimation> spriteAnimation; 
    float radius;
public:
    BulletManager(std::shared_ptr<Game> game, std::shared_ptr<SpriteAnimation> spriteAnimation, float radius);
    ~BulletManager();

    virtual void Update();
    virtual void Draw();

    void CreateBullet(Vector2 position, Vector2 velocity);
    void CreateBullet(Vector2 position, Vector2 direction, float speed);
    void CreateBullet(Vector2 position, float angle, float speed, bool isRadian = true);
};

