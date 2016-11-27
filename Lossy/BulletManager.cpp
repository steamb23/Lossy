#include "stdafx.h"
#include "BulletManager.h"


BulletManager::BulletManager()
{
}


BulletManager::~BulletManager()
{
}

void BulletManager::Update()
{
    for (auto iterator = bulletList.begin(); iterator != bulletList.end(); iterator++)
    {
        if ((*iterator)->IsDestroyed())
        {
            iterator = bulletList.erase(iterator);
        }
        (*iterator)->Update();
    }
}

void BulletManager::Draw()
{
    for (auto iterator = bulletList.begin(); iterator != bulletList.end(); iterator++)
    {
        if ((*iterator)->IsDestroyed())
        {
            iterator = bulletList.erase(iterator);
        }
        (*iterator)->Update();
    }
}
