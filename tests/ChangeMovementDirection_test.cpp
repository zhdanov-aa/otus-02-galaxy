#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ChangeMovementDirection.h>
#include <IMovementDirectionObject_mock.h>
#include <InvalidArgument.h>
#include <UnavailableAction.h>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

TEST(ChangeMovementDirection, NormalExecution)
{
    IMovementDirectionObjectMockPtr object = make_shared<IMovementDirectionObjectMock>();

    EXPECT_CALL(*object, getDirection()).WillOnce(Return(Angle(45)));
    EXPECT_CALL(*object, getInstantChange()).WillOnce(Return(Angle(15)));
    EXPECT_CALL(*object, setDirection(Angle(60)));

    ChangeMovementDirection cmd(object);

    EXPECT_NO_THROW(cmd.Execute());
}

TEST(ChangeMovementDirection, InvalidArgumentThrowing)
{
    ChangeMovementDirection cmd(nullptr);

    try
    {
        cmd.Execute();
        FAIL();
    }
    catch (InvalidArgument *pException)
    {
        delete pException;
        SUCCEED();
    }
}

TEST(ChangeMovementDirection, UnavailableActionCatching_getDirection)
{
    IMovementDirectionObjectMockPtr object = make_shared<IMovementDirectionObjectMock>();

    EXPECT_CALL(*object, getDirection()).WillOnce(Throw(new UnavailableAction("getDirection")));
    EXPECT_CALL(*object, getInstantChange()).Times(AnyNumber()).WillOnce(Return(Angle(15)));
    
    ChangeMovementDirection cmd(object);

    EXPECT_NO_THROW(cmd.Execute());
}

// TEST(ChangeMovementDirection, OtherExceptionsSkipping)
// {

// }