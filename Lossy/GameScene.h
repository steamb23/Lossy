#pragma once
#include "Scene.h"
#include "Background.h"
#include "SpriteAnimation.h"
#include "PlayerObject.h"
#include "BossObject.h"
#include "BulletManager.h"
#include "StatusBar.h"

class GameScene :
    public Scene
{
    std::shared_ptr<Background> back;
    std::shared_ptr<PlayerObject> player;
    std::shared_ptr<BossObject> boss;
    
    std::shared_ptr<BulletManager> playerBullets;
    std::shared_ptr<BulletManager> enemyBullets;

    std::shared_ptr<StatusBar> statusBar;

    bool gameCleared;

    HBITMAP gameoverBitmap;
    HBITMAP gameclearBitamp;
public:
    GameScene(std::shared_ptr<Game> game);
    virtual ~GameScene();

    virtual void Update();
    virtual void Draw();

    std::shared_ptr<StatusBar> GetStatusBar() { return this->statusBar; };
    std::shared_ptr<BulletManager> GetPlayerBullets() { return this->playerBullets; };
    std::shared_ptr<BulletManager> GetEnemyBullets() { return this->enemyBullets; };

    std::shared_ptr<PlayerObject> GetPlayerObject() { return this->player; };
    std::shared_ptr<BossObject> GetBossObject() { return this->boss; };
    bool IsCleared() { return gameCleared; };
};

