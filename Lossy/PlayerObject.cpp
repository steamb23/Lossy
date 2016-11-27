#include "stdafx.h"
#include "PlayerObject.h"


PlayerObject::PlayerObject(std::shared_ptr<Game> game)
    : GameObject(game)
{
    // 스프라이트 초기화
    spriteAnimation = std::make_shared<SpriteAnimation>();
}

PlayerObject::~PlayerObject()
{
}
