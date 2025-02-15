#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <CheckFuel.h>
#include <InvalidArgument.h>
#include <NotEnoughFuel.h>
#include <IFuelObject_mock.h>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;

TEST(CheckFuel, InvalidArgument)
{
    CheckFuel cmd(nullptr);
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

TEST(CheckFuel, EnoughFuel)
{
    shared_ptr<IFuelObjectMock> obj = make_shared<IFuelObjectMock>();
    CheckFuel cmd(obj);

    EXPECT_CALL(*obj, getLevel()).WillOnce(Return(FuelLevel(100)));
    EXPECT_CALL(*obj, getConsumption()).WillOnce(Return(FuelLevel(40)));

    EXPECT_NO_THROW(cmd.Execute());
}

TEST(CheckFuel, NotEnoughFuel)
{
    shared_ptr<IFuelObjectMock> obj = make_shared<IFuelObjectMock>();
    CheckFuel cmd(obj);

    EXPECT_CALL(*obj, getLevel()).WillOnce(Return(FuelLevel(30)));
    EXPECT_CALL(*obj, getConsumption()).WillOnce(Return(FuelLevel(40)));

    try
    {
        cmd.Execute();
        FAIL();
    }
    catch(IException *exception)
    {
        EXPECT_NE(dynamic_cast<NotEnoughFuel*>(exception), nullptr);
        delete exception;
    }
}

TEST(CheckFuel, TranslateExceptions)
{
    shared_ptr<IFuelObjectMock> obj = make_shared<IFuelObjectMock>();
    CheckFuel cmd(obj);

    EXPECT_CALL(*obj, getLevel()).Times(AnyNumber()).WillRepeatedly(Throw(42));
    EXPECT_CALL(*obj, getConsumption()).Times(AnyNumber()).WillRepeatedly(Throw(39));

    EXPECT_ANY_THROW(cmd.Execute());
}