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
	currentScene = scene;
}

void SceneManager::Update()
{
	if (currentScene != null)
		currentScene->Update();
}

void SceneManager::Draw()
{
	if (currentScene != null)
		currentScene->Draw();
}
