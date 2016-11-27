#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(std::shared_ptr<Game> game)
{
    this->game = game;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
}

void GameObject::Draw()
{
}
