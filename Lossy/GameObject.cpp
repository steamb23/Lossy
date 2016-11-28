#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(std::shared_ptr<Game> game, float radius)
{
    this->game = game;
    this->radius = radius;
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

bool GameObject::IsCollision(std::shared_ptr<GameObject> another)
{
    float distance;

    XMVECTOR thisPos = XMLoadFloat2(&position);
    XMVECTOR anotherPos = XMLoadFloat2( &another->position);

    XMStoreFloat(&distance, XMVector2LengthSq(thisPos - anotherPos));

    float totalRadius = (radius + another->GetRadius());
    totalRadius *= totalRadius;

    return distance < totalRadius;
}
