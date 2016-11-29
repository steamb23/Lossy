#pragma once
#include "GameObject.h"
#include "SpriteAnimation.h"
#include "BulletManager.h"

class LossyGame;
class BossObject :
    public GameObject
{
    std::shared_ptr<SpriteAnimation> spriteAnimation;
    std::shared_ptr<BulletManager> bulletManager;
public:
    BossObject(std::shared_ptr<Game> game, std::shared_ptr<BulletManager> bulletManager);
    virtual ~BossObject();

    virtual void Update();
    virtual void Draw();

private:
    void Shot();
    bool ShotPattern1(float angle);
};

