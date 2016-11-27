#pragma once
#include <memory>
#include "GameTime.h"
#include "DrawManager.h"
#include "SceneManager.h"

class Game : protected std::enable_shared_from_this<Game>
{
public:
    Game(HWND hWnd, HINSTANCE hInst);
    virtual ~Game();

    int Run();

    bool IsRun() { return isRun; };

    void PreInitialize();
    void PreUpdate();
    void PreDraw();

    virtual void Initialize();
    virtual void Update();
    virtual void Draw();

    void ScreenClear();
    void DrawFPS();

    BOOL IsFrameLimit() { return isFrameLimit; };
    void IsFrameLimit(BOOL value) { this->isFrameLimit = value; };

    std::shared_ptr<SceneManager> GetSceneManager() const { return sceneManager; };
protected:
    HWND hWnd;
    HINSTANCE hInst;
    BOOL isFrameLimit;
    std::shared_ptr<GameTime> gameTime;
    std::shared_ptr<SceneManager> sceneManager;
private:
    BOOL isRun;
};
