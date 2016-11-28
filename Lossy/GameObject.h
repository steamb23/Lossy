#pragma once
#include <memory>
#include "GameMath.h"
class Game;
class GameObject : protected std::enable_shared_from_this<GameObject>
{
    std::weak_ptr<Game> game;
    bool isInitialized;
public:
    GameObject(std::shared_ptr<Game> game, float radius);
    virtual ~GameObject();

    Vector2 GetPosition() const { return position; };
    Vector2 SetPosition(Vector2 value) { this->position = value; };

    virtual void Update();
    virtual void Draw();

    std::shared_ptr<Game> GetGame() { return game.lock(); };

    void SetRadius(float value) { radius = value; };
    float GetRadius() { return radius; };

    bool IsCollision(std::shared_ptr<GameObject> another);
protected:
    Vector2 position;
    float radius;
};