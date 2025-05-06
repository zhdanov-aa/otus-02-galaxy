#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <memory>
#include <string>
#include <any>

class IGameObject
{
public:
    virtual ~IGameObject() = default;

    virtual void setProperty(const std::string& key, const std::any& value) = 0;
    virtual std::any getProperty(const std::string& key) = 0;
};

using IGameObjectPtr = std::shared_ptr<IGameObject>;

#endif // IGAMEOBJECT_H
