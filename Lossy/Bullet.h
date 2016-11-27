#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
public:
	Bullet();
	virtual ~Bullet();

	virtual void Update();
	virtual void Draw();
};

