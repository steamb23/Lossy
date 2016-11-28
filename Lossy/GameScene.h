#pragma once
#include "Scene.h"
#include "Background.h"
#include "SpriteAnimation.h"
#include "PlayerObject.h"
#include "BossObject.h"
#include "BulletManager.h"

class GameScene :
    public Scene
{
    std::shared_ptr<Background> back;
    std::shared_ptr<PlayerObject> player;
    std::shared_ptr<BossObject> boss;
    
    std::shared_ptr<BulletManager> playerBullets;
    std::shared_ptr<BulletManager> enemyBullets;
public:
    GameScene(std::shared_ptr<Game> game);
    virtual ~GameScene();

    virtual void Update();
    virtual void Draw();
};

