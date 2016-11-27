#pragma once
#include "GameObject.h"
#include "SpriteAnimation.h"
class PlayerObject :
    public GameObject
{
    std::shared_ptr<SpriteAnimation> spriteAnimation;
public:
    PlayerObject(std::shared_ptr<Game> game);
    virtual ~PlayerObject();
};

