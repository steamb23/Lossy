#pragma once
#include <memory>
#include "Scene.h"
class SceneManager
{
    std::shared_ptr<Scene> currentScene;
    std::shared_ptr<Scene> nextScene;
public:
    SceneManager();
    ~SceneManager();

    void ChangeScene(std::shared_ptr<Scene> scene);
    std::shared_ptr<Scene> GetCurrentScene() { return currentScene; };

    void Update();
    void Draw();
};

