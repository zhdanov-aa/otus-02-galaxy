#ifndef __IFUELOBJECT_H_INCLUDED__
#define __IFUELOBJECT_H_INCLUDED__

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IFuelObject.h>

class IFuelObjectMock: public IFuelObject
{
public:
    MOCK_METHOD(FuelLevel, getLevel, ());
    MOCK_METHOD(void, setLevel, (FuelLevel));

    MOCK_METHOD(FuelLevel, getConsumption, ());
};

#endif