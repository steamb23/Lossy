#pragma once
#include <windows.h>
class Game;
class Background
{
    HBITMAP background1;
    HBITMAP background2;

    float x1;
    float x2;
    
    std::shared_ptr<Game> game;
public:
    Background(std::shared_ptr<Game> game);
    ~Background();

    void Update();
    void Draw();
};

