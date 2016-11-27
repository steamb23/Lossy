#pragma once
#include "Scene.h"
class GameScene :
    public Scene
{
public:
    GameScene(std::shared_ptr<Game> game);
    virtual ~GameScene();

    virtual void Update();
    virtual void Draw();
};

