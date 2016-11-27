#include "stdafx.h"
#include "PlayerObject.h"


PlayerObject::PlayerObject(std::shared_ptr<Game> game)
    : GameObject(game)
{
    // ��������Ʈ �ʱ�ȭ
    spriteAnimation = std::make_shared<SpriteAnimation>();
}

PlayerObject::~PlayerObject()
{
}
