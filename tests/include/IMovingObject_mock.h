#ifndef __IMOVINGOBJECT_MOCK_H_INCLUDED__
#define __IMOVINGOBJECT_MOCK_H_INCLUDED__

#include <IMovingObject.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class IMovingObjectMock: public IMovingObject
{
public:
    MOCK_METHOD(Vector2D, getLocation, ());
    MOCK_METHOD(Vector2D, getVelocity, ());
    MOCK_METHOD(void, setLocation, (Vector2D));
};

#endif