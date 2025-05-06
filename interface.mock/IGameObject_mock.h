#ifndef _IGAMEOBJECT_MOCK_INCLUDED_
#define _IGAMEOBJECT_MOCK_INCLUDED_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IGameObject.h>
#include <string>
#include <any>
#include <memory>

class IGameObjectMock: public IGameObject
{
public:
    MOCK_METHOD(void, setProperty, (const std::string&, const std::any&));
    MOCK_METHOD(std::any, getProperty, (const std::string&));
};

Using IGameObjectMockPtr = std::shared_ptr<IGameObjectMock>;

#endif
