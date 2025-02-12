#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <CheckFuel.h>
#include <InvalidArgument.h>
#include <NotEnoughFuel.h>
#include <IFuelObject_mock.h>

using namespace std;
using ::testing::Throw;

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

// TEST(CheckFuel, EnoughFuel)
// {
    
// }

// TEST(CheckFuel, NotEnoughFuel)
// {
    
// }

// TEST(CheckFuel, TranslateExceptions)
// {
    
// }