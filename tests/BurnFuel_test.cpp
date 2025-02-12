#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <BurnFuel.h>
#include <InvalidArgument.h>
#include <NotEnoughFuel.h>
#include <IFuelObject_mock.h>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;

TEST(BurnFuel, InvalidArgument)
{
    BurnFuel cmd(nullptr);
    try
    {
        cmd.Execute();
        FAIL();
    }
    catch(IException *exception)
    {
        EXPECT_NE(dynamic_cast<InvalidArgument*>(exception), nullptr);
        delete exception;
    }
}

TEST(BurnFuel, BurningFuel) 
{
    shared_ptr<IFuelObjectMock> obj = make_shared<IFuelObjectMock>();
    BurnFuel cmd(obj);

    EXPECT_CALL(*obj, getLevel()).WillOnce(Return(FuelLevel(100)));
    EXPECT_CALL(*obj, getConsumption()).WillOnce(Return(FuelLevel(40)));
    EXPECT_CALL(*obj, setLevel(FuelLevel(60)));

    EXPECT_NO_THROW(cmd.Execute());
}

TEST(BurnFuel, ExceptionFromGetLevel) 
{
    shared_ptr<IFuelObjectMock> obj = make_shared<IFuelObjectMock>();
    BurnFuel cmd(obj);

    EXPECT_CALL(*obj, getLevel()).WillOnce(Throw(100));
    EXPECT_CALL(*obj, getConsumption()).Times(AnyNumber()).WillOnce(Return(FuelLevel(40)));
    EXPECT_CALL(*obj, setLevel(FuelLevel(60))).Times(AnyNumber());

    EXPECT_ANY_THROW(cmd.Execute());
}

TEST(BurnFuel, ExceptionFromGetConsumption) 
{
    shared_ptr<IFuelObjectMock> obj = make_shared<IFuelObjectMock>();
    BurnFuel cmd(obj);

    EXPECT_CALL(*obj, getLevel()).Times(AnyNumber()).WillOnce(Return(FuelLevel(100)));
    EXPECT_CALL(*obj, getConsumption()).WillOnce(Throw(40));
    EXPECT_CALL(*obj, setLevel(FuelLevel(60))).Times(AnyNumber());

    EXPECT_ANY_THROW(cmd.Execute());
}

TEST(BurnFuel, ExceptionFromSetLevel) 
{
    shared_ptr<IFuelObjectMock> obj = make_shared<IFuelObjectMock>();
    BurnFuel cmd(obj);

    EXPECT_CALL(*obj, getLevel()).Times(AnyNumber()).WillOnce(Return(FuelLevel(100)));
    EXPECT_CALL(*obj, getConsumption()).Times(AnyNumber()).WillOnce(Return(FuelLevel(40)));
    EXPECT_CALL(*obj, setLevel(_)).WillOnce(Throw(FuelLevel(60)));

    EXPECT_ANY_THROW(cmd.Execute());
}