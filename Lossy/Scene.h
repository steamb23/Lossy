#pragma once
#include <memory>
class Game;
class Scene : protected std::enable_shared_from_this<Scene>
{
    std::weak_ptr<Game> game;

    bool isInitialized;
public:
    Scene(std::shared_ptr<Game> game);
    virtual ~Scene();

    virtual void Update();
    virtual void Draw();
};