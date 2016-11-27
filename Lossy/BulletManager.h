#pragma once
#include <list>
#include "Bullet.h"
class BulletManager
{
    std::list<std::shared_ptr<Bullet>> bulletList;
public:
    BulletManager();
    ~BulletManager();

    virtual void Update();
    virtual void Draw();
};

