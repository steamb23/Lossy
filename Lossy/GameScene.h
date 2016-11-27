#pragma once
#include "Scene.h"
#include "Background.h"
class GameScene :
    public Scene
{
    std::shared_ptr<Background> back;
public:
    GameScene(std::shared_ptr<Game> game);
    virtual ~GameScene();

    virtual void Update();
    virtual void Draw();
};

