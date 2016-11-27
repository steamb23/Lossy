#pragma once
#include <memory>
#include "GameMath.h"
class GameObject : protected std::enable_shared_from_this<GameObject>
{
	bool isInitialized;
public:
	GameObject();
	virtual ~GameObject();

	Vector2 GetPosition() const { return position; };
	Vector2 SetPosition(Vector2 value) { this->position = value; };

	virtual void Update();
	virtual void Draw();
protected:
	Vector2 position;
};