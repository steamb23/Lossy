#pragma once
#include <memory>
#include "Scene.h"
class SceneManager
{
    std::shared_ptr<Scene> currentScene;
public:
    SceneManager();
    ~SceneManager();

    void ChangeScene(std::shared_ptr<Scene> scene);

    void Update();
    void Draw();
};

