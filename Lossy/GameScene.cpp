#include "stdafx.h"
#include "GameScene.h"
#include "LossyGame.h"
#include "Resource.h"

GameScene::GameScene(std::shared_ptr<Game> game)
    : Scene(game)
{
    back = std::make_shared<Background>(GetGame());
    auto sprite = std::make_shared<Sprite>(DrawManager::Inst()->LoadBitmapFromResource(IDB_PLAYER), std::vector<RECT>({ {0,0,128,128},{128,0,128,128} }));
    //characterTest = std::make_shared<SpriteAnimation>(sprite, 2);

    std::shared_ptr<Sprite> playerBulletSprite = std::make_shared<Sprite>(DrawManager::Inst()->LoadBitmapFromResource(IDB_PBULLET), std::vector<RECT>({ {0,0,32,32} }));
    std::shared_ptr<SpriteAnimation> playerBulletSpriteAnimation = std::make_shared<SpriteAnimation>(playerBulletSprite, 0);
    playerBullets = std::make_shared<BulletManager>(GetGame(), playerBulletSpriteAnimation, 16);

    std::shared_ptr<Sprite> enemyBulletSprite = std::make_shared<Sprite>(DrawManager::Inst()->LoadBitmapFromResource(IDB_BULLET), std::vector<RECT>({ { 0,0,32,32 },{ 32,0,32,32 },{ 64,0,32,32 },{ 96,0,32,32 } }));
    std::shared_ptr<SpriteAnimation> enemyBulletSpriteAnimation = std::make_shared<SpriteAnimation>(enemyBulletSprite, 6);
    enemyBullets = std::make_shared<BulletManager>(GetGame(), enemyBulletSpriteAnimation, 16);

    player = std::make_shared<PlayerObject>(GetGame(), playerBullets);
    boss = std::make_shared<BossObject>(GetGame(), enemyBullets);

    statusBar = std::make_shared<StatusBar>();

    gameCleared = false;
}

GameScene::~GameScene()
{
}

void GameScene::Update()
{
    back->Update();
    player->Update();
    if (statusBar->GetValue() < 0)
        gameCleared = true;
    if (!gameCleared)
    {
        boss->Update();
        enemyBullets->Update();
    }

    playerBullets->Update();
    //characterTest->Update();
}

void GameScene::Draw()
{
    back->Draw();
    player->Draw();
    if (!gameCleared)
    {
        boss->Draw();
        enemyBullets->Draw();

        statusBar->Draw();
    }

    playerBullets->Draw();
    //characterTest->Draw(100,300);
}
