#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <CheckFuel.h>
#include <InvalidArgument.h>
#include <NotEnoughFuel.h>
#include <IFuelObject_mock.h>

using namespace std;
using ::testing::Throw;
using ::testing::Return;

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

    EXPECT_CALL(*obj, getFuelLevel()).WillOnce(Return(FuelLevel(100)));
    EXPECT_CALL(*obj, getConsumption()).WillOnce(Return(FuelLevel(40)));
    EXPECT_CALL(*obj, setFuelLevel(FuelLevel(60)));

    EXPECT_NO_THROW(cmd.Execute());
}

// TEST(CheckFuel, NotEnoughFuel)
// {
    
// }

// TEST(CheckFuel, TranslateExceptions)
// {
    
// }