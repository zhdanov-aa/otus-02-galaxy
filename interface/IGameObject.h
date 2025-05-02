#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <memory>

class IGameObject
{
public:
    virtual ~IGameObject() = default;
};

using IGameObjectPtr = std::shared_ptr<IGameObject>;

#endif // IGAMEOBJECT_H
