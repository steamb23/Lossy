#include "stdafx.h"
#include "GameScene.h"
#include "LossyGame.h"


GameScene::GameScene(std::shared_ptr<Game> game)
    : Scene(game)
{
    back = std::make_shared<Background>(GetGame());
}

GameScene::~GameScene()
{
}

void GameScene::Update()
{
    back->Update();
}

void GameScene::Draw()
{
    back->Draw();
}
