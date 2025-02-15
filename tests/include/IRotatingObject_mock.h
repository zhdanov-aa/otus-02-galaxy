#ifndef __IROTATINGOBJECTMOCK_H_INCLUDED__
#define __IROTATINGOBJECTMOCK_H_INCLUDED__

#include <IRotatingObject.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

class IRotatingObjectMock: public IRotatingObject
{
public:
    MOCK_METHOD(Angle, getAngle, ());
    MOCK_METHOD(Angle, getRotationSpeed, ());
    MOCK_METHOD(void, setAngle, (Angle));
};

typedef std::shared_ptr<IRotatingObjectMock> IRotatingObjectMockPtr;

#endif