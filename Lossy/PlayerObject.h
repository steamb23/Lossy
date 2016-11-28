#pragma once
#include "GameObject.h"
#include "SpriteAnimation.h"
#include "BulletManager.h"

class PlayerObject :
    public GameObject
{
    std::shared_ptr<SpriteAnimation> spriteAnimation;
    std::shared_ptr<BulletManager> bulletManager;

    bool zKeyPressed;
public:
    PlayerObject(std::shared_ptr<Game> game, std::shared_ptr<BulletManager> bulletManager);
    virtual ~PlayerObject();

    virtual void Update();
    virtual void Draw();
};

