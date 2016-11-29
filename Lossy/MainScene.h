#pragma once
#include "Scene.h"
class MainScene :
    public Scene
{
    HBITMAP bitmap1;
    HBITMAP bitmap2;

    int frames;
    bool textDraw;
public:
    MainScene(std::shared_ptr<Game> game);
    virtual ~MainScene();

    virtual void Update();
    virtual void Draw();
};

