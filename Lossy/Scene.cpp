#include "stdafx.h"
#include "Scene.h"
#include "Game.h"

Scene::Scene(std::shared_ptr<Game> game)
{
	this->game = game;
}


Scene::~Scene()
{
}

void Scene::Update()
{
}

void Scene::Draw()
{
}
