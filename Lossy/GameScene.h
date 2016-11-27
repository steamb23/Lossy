#pragma once
#include "Scene.h"
#include "Background.h"
#include "SpriteAnimation.h"
class GameScene :
    public Scene
{
    std::shared_ptr<Background> back;
    std::shared_ptr<SpriteAnimation> characterTest;
public:
    GameScene(std::shared_ptr<Game> game);
    virtual ~GameScene();

    virtual void Update();
    virtual void Draw();
};

