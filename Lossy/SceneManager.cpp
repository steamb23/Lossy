#include "stdafx.h"
#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::ChangeScene(std::shared_ptr<Scene> scene)
{
    nextScene = scene;
}

void SceneManager::Update()
{
    currentScene = nextScene;
    if (currentScene != nullptr)
        currentScene->Update();
}

void SceneManager::Draw()
{
    if (currentScene != nullptr)
        currentScene->Draw();
}
