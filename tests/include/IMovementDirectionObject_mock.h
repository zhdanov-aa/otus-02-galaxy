#ifndef __IMOVEMENTDIRECTIONOBJECTMOCK_H_INCLUDED__
#define __IMOVEMENTDIRECTIONOBJECTMOCK_H_INCLUDED__

#include <IMovementDirectionObject.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

class IMovementDirectionObjectMock: public IMovementDirectionObject
{
public:
    MOCK_METHOD(Angle, getDirection, ());
    MOCK_METHOD(Angle, getInstantChange, ());
    MOCK_METHOD(void, setDirection, (Angle));
};

typedef std::shared_ptr<IMovementDirectionObjectMock> IMovementDirectionObjectMockPtr;

#endif