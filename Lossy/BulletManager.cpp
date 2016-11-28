#include "stdafx.h"
#include "BulletManager.h"


BulletManager::BulletManager(std::shared_ptr<Game> game, std::shared_ptr<SpriteAnimation> spriteAnimation, float radius)
{
    this->game = game;
    this->spriteAnimation = spriteAnimation;
    this->radius = radius;
}

BulletManager::~BulletManager()
{
}

void BulletManager::Update()
{
    for (auto iterator = bulletList.begin(); iterator != bulletList.end(); iterator++)
    {
        auto position = (*iterator)->GetPosition();
        if (position.x < -100)
        {
            (*iterator)->Destroy();
        }
        if (position.x > 800 + 100)
        {
            (*iterator)->Destroy();
        }
        if (position.y < -100)
        {
            (*iterator)->Destroy();
        }
        if (position.y > 800 + 100)
        {
            (*iterator)->Destroy();
        }
        if ((*iterator)->IsDestroyed())
        {
            iterator = bulletList.erase(iterator);
        }
        if (iterator == bulletList.end())
            break;
        (*iterator)->Update();
    }
}

void BulletManager::Draw()
{
    for (auto iterator = bulletList.begin(); iterator != bulletList.end(); iterator++)
    {
        (*iterator)->Draw();
    }
}

void BulletManager::CreateBullet(Vector2 position, Vector2 velocity)
{
    auto temp = std::make_shared<Bullet>(game.lock(), position, spriteAnimation, radius, velocity);
    bulletList.push_back(temp);
}

void BulletManager::CreateBullet(Vector2 position, Vector2 direction, float speed)
{
    XMVECTOR velVec = XMLoadFloat2(&direction);
    // velVec = XMVector2Normalize(velVec);
    velVec * speed;
    Vector2 velocity;
    XMStoreFloat2(&velocity, velVec);
    this->CreateBullet(position, velocity);
}

void BulletManager::CreateBullet(Vector2 position, float angle, float speed, bool isRadian)
{
    if (!isRadian)
    {
        angle = XM_PI / 180 * angle;
    }
    Vector2 direction = Vector2(cos(angle), sin(angle));
    this->CreateBullet(position, direction, speed);
}

std::shared_ptr<Bullet> BulletManager::CheckCollision(std::shared_ptr<GameObject> object)
{
    for (auto iterator = bulletList.begin(); iterator != bulletList.end(); iterator++)
    {
        if (object->IsCollision(*iterator))
            return (*iterator);
    }
    return nullptr;
}
